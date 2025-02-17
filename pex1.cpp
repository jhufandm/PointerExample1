#include <iostream>
using namespace std;

//method 1: 
float calAverage(float grades[], int sizeArray){
    float total = 0;
    for (int i=0; i<sizeArray; i++){
        //total += grades[i];
        total+= *(grades+i);
    }
    return total/sizeArray;
}

//method 2: 
float calAverage2(float* grades, int sizeArray){
    float total = 0;
    for (int i=0; i<sizeArray; i++){
        //total += grades[i];
        total += *(grades+i);
    }
    return total/sizeArray;

}

int main(){
    // int temp = 10;
    // int* grade; //an integer pointer
    // grade = &temp; //give the address of temp object to grade

    // cout<<*grade<<endl;
    // cout<<grade<<endl;

    float* scores=nullptr; //nullptr is an empty pointer
    int numStudents;
    cout<<"How many students in your class:";
    cin>>numStudents;
    scores = new float(numStudents); //dynamically allocate enough memmory to hold

    for (int i=0;i<numStudents; i++){
        cout<<"student "<<i+1<<": ";
        //cin>>scores[i]; //method 1
        cin>>*(scores + i); //method 2
    }

    cout<<"The average score is "<<calAverage(scores, numStudents)<<endl;
    cout<<"The average score is "<<calAverage2(scores, numStudents)<<endl;

    cout<<"We have more students joined the class!"<<endl;
    float* newScores = nullptr;
    //dynamically allocate another array with double the size
    newScores = new float(2*numStudents); 
    //Copy everything from the old array to the new array
    for (int i=0;i<numStudents;i++){
        newScores[i] = scores[i];
        //*(newScores + i) = *(scores+i);
    }
    delete[] scores; //release these memory locations for other to use
    scores = newScores; //let scores point to the new array
    cout<<"Enter the score of the new student: ";
    cin>>scores[numStudents]; //Enter another item
    numStudents++;

    cout<<"The new average score is "<<calAverage(scores, numStudents)<<endl;

    return 0;
}