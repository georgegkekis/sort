#include <stdint.h>
#include <string.h>
#include <stdio.h>
typedef struct {
        uint8_t bleName[16];
        uint8_t bleMac[6];
        uint8_t major[2];
        uint8_t minor[2];
        int8_t  bleRssi;
        int32_t avg_rssi;
        int32_t count;
} Ble_scanRsp_t;


int lora_ble_saved_index = 8;
Ble_scanRsp_t ble_to_lora[8] = {
                                 [0].avg_rssi = 7,
                                 [0].count =    7,

                                 [1].avg_rssi = 6,
                                 [1].count =    6,

                                 [2].avg_rssi = 5,
                                 [2].count =    5,

                                 [3].avg_rssi = 33,
                                 [3].count =    4,

                                 [4].avg_rssi = 3,
                                 [4].count =    312,

                                 [5].avg_rssi = 233,
                                 [5].count =    2,

                                 [6].avg_rssi = 1,
                                 [6].count =    1,

                                 [7].avg_rssi = 0,
                                 [7].count =    0
};


void sort_data(void)
{
  Ble_scanRsp_t temp[1];
  if(lora_ble_saved_index > 1)
  {
     for(int i = 0; i < lora_ble_saved_index; i++)
     {
        for(int j = i + 1; j < lora_ble_saved_index; j++)
        {
           printf("i:%d j:%d %d >? %d\r\n",i,j, (ble_to_lora[i+1].avg_rssi * ble_to_lora[i+1].count), (ble_to_lora[i].avg_rssi * ble_to_lora[i].count));
           if((ble_to_lora[i].avg_rssi * ble_to_lora[i].count) < (ble_to_lora[j].avg_rssi * ble_to_lora[j].count))
           {
              memcpy((&temp[0]), (&ble_to_lora[j]), sizeof(Ble_scanRsp_t));
              memcpy(&ble_to_lora[j], &ble_to_lora[i], sizeof(Ble_scanRsp_t));
              memcpy(&ble_to_lora[i], &temp[0], sizeof(Ble_scanRsp_t));
              printf("Did a swap:i:%d,avg_rssi:%d, count:%d   j:%d, avg_rssi:%d, count:%d\r\n", i, ble_to_lora[i].avg_rssi, ble_to_lora[i].count, j, ble_to_lora[j].avg_rssi, ble_to_lora[j].count);
           }
        }
        printf("\r\n");
     }
  }
}

void main()
{
  for(int i = 0; i < lora_ble_saved_index; i++)
  {
     printf("i:%d,***:%d \tavg_rssi:%d, count:%d\r\n", i, ble_to_lora[i].avg_rssi* ble_to_lora[i].count, ble_to_lora[i].avg_rssi, ble_to_lora[i].count);
  }
printf("\r\n");
  sort_data();
printf("\r\n");
  for(int i = 0; i < lora_ble_saved_index; i++)
  {
     printf("i:%d,***:%d \tavg_rssi:%d, count:%d\r\n", i, ble_to_lora[i].avg_rssi* ble_to_lora[i].count, ble_to_lora[i].avg_rssi, ble_to_lora[i].count);
  }
}
