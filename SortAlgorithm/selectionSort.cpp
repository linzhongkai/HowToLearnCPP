//使用的是double
void selectionSort(double list[], int size){
    for (int i = 0; i < size - 1; i++){
        double minValue = list[i];
        int minIndex = i;
        for (int j = i + 1; j < size; j++){
            if (minValue > list[j]){
                minValue = list[j];
                minIndex = j;
            }
        }
        if(minIndex != i){
            list[minIndex] = list[i];
            list[i] = minValue;
        }
    }
}

