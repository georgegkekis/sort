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

// Perfectly sorted
/*Ble_scanRsp_t ble_to_lora[8] = {*/
/*                                 [0].avg_rssi = 7,*/
/*                                 [0].count =    7,*/

/*                                 [1].avg_rssi = 6,*/
/*                                 [1].count =    6,*/

/*                                 [2].avg_rssi = 5,*/
/*                                 [2].count =    5,*/

/*                                 [3].avg_rssi = 4,*/
/*                                 [3].count =    4,*/

/*                                 [4].avg_rssi = 3,*/
/*                                 [4].count =    3,*/

/*                                 [5].avg_rssi = 2,*/
/*                                 [5].count =    2,*/

/*                                 [6].avg_rssi = 1,*/
/*                                 [6].count =    1,*/

/*                                 [7].avg_rssi = 0,*/
/*                                 [7].count =    0*/
/*};*/

/*// Perfectly unsorted*/
/*Ble_scanRsp_t ble_to_lora[8] = {*/
/*                                 [0].avg_rssi = 0,*/
/*                                 [0].count =    0,*/
/*                                 [1].avg_rssi = 1,*/
/*                                 [1].count =    1,*/
/*                                 [2].avg_rssi = 2,*/
/*                                 [2].count =    2,*/
/*                                 [3].avg_rssi = 3,*/
/*                                 [3].count =    3,*/
/*                                 [4].avg_rssi = 4,*/
/*                                 [4].count =    4,*/
/*                                 [5].avg_rssi = 5,*/
/*                                 [5].count =    5,*/
/*                                 [6].avg_rssi = 6,*/
/*                                 [6].count =    6,*/
/*                                 [7].avg_rssi = 7,*/
/*                                 [7].count =    7*/
/*};*/

/*// Unsorted*/
/*Ble_scanRsp_t ble_to_lora[8] = {*/
/*                                 [0].avg_rssi = 7,*/
/*                                 [0].count =    7,*/
/*                                 [1].avg_rssi = 4,*/
/*                                 [1].count =    4,*/
/*                                 [2].avg_rssi = 5,*/
/*                                 [2].count =    5,*/
/*                                 [3].avg_rssi = 2,*/
/*                                 [3].count =    2,*/
/*                                 [4].avg_rssi = 0,*/
/*                                 [4].count =    0,*/
/*                                 [5].avg_rssi = 1,*/
/*                                 [5].count =    1,*/
/*                                 [6].avg_rssi = 3,*/
/*                                 [6].count =    3,*/
/*                                 [7].avg_rssi = 6,*/
/*                                 [7].count =    6*/
/*};*/

// Empty values
/*Ble_scanRsp_t ble_to_lora[8] = {*/
/*                                 [0].avg_rssi = 0,*/
/*                                 [0].count =    0,*/
/*                                 [1].avg_rssi = 0,*/
/*                                 [1].count =    0,*/
/*                                 [2].avg_rssi = 0,*/
/*                                 [2].count =    0,*/
/*                                 [3].avg_rssi = 0,*/
/*                                 [3].count =    0,*/
/*                                 [4].avg_rssi = 0,*/
/*                                 [4].count =    0,*/
/*                                 [5].avg_rssi = 0,*/
/*                                 [5].count =    0,*/
/*                                 [6].avg_rssi = 0,*/
/*                                 [6].count =    0,*/
/*                                 [7].avg_rssi = 0,*/
/*                                 [7].count =    0*/
/*};*/

Ble_scanRsp_t ble_to_lora[8] = {};

int32_t product(int a)
{
    return ble_to_lora[a].avg_rssi * ble_to_lora[a].count;
}

void swap(int i, int j)
{
    Ble_scanRsp_t temp[1];
    memcpy((&temp[0]), (&ble_to_lora[j]), sizeof(Ble_scanRsp_t));
    memcpy(&ble_to_lora[j], &ble_to_lora[i], sizeof(Ble_scanRsp_t));
    memcpy(&ble_to_lora[i], &temp[0], sizeof(Ble_scanRsp_t));
}

void print_struct()
{
  for(int i = 0; i < lora_ble_saved_index; i++)
  {
     printf("i:%d, Prod:%d \trssi:%d, count:%d\r\n", i, product(i), ble_to_lora[i].avg_rssi, ble_to_lora[i].count);
  }
  printf("\r\n");
}

void sort_data(void)
{
   for(int i = 0; i < lora_ble_saved_index; i++)
   {
      for(int j = i + 1; j < lora_ble_saved_index; j++)
      {
         printf("i:%d j:%d %d ?< %d\r\n",i,j, product(i), product(j));
         if(product(i) < product(j))
         {
            swap(i, j);
            printf("Swap:i:%d, prod:%d rssi:%d, count:%d <-> j:%d, prod:%d rssi:%d, count:%d\r\n", i, product(i), ble_to_lora[i].avg_rssi, ble_to_lora[i].count, j, product(j), ble_to_lora[j].avg_rssi, ble_to_lora[j].count);
         }
      }
      printf("\r\n");
   }
}

void main()
{
  print_struct();
  sort_data();
  print_struct();
}
