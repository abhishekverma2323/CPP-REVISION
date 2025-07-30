#include<iostream>
using namespace std;

void transpose(int arr[][3],int row,int column,int copy[][3])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0;j<column;j++)
        {
            copy[j][i]=arr[i][j];
        }
    }
}

void search(int arr[][3],int row,int column,int target)
{
    for(int i=0;i<row;i++)
    {
       for(int j=0;j<column;j++)
       {
           if(arr[i][j]==target)
           {
               cout<<"Element found at index: "<<i<<" "<<j<<endl;
           }
       }
    }
    
}

void sum_column_wise(int arr[][3],int row,int column)
{
    for(int j=0;j<column;j++)
    {
       int sum=0;
       for(int i=0;i<row;i++)
       {
           sum=sum+arr[i][j];
       }
       cout<<"SUM OF column "<<j+1<<" is "<<sum<<endl;
    }
    
}

void sum_row_wise(int arr[][3],int row,int column)
{
    for(int i=0;i<row;i++)
    {
       int sum=0;
       for(int j=0;j<column;j++)
       {
           sum=sum+arr[i][j];
       }
       cout<<"SUM OF ROW "<<i<<" is "<<sum<<endl;
    }
    
}

void input_2d_array(int arr[][3],int row,int column)
{
    cout<<"Enter the elements for 3 X 3 matrix"<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cin>>arr[i][j];
        }
    }
}

void display_2d_array(int arr[][3],int row,int column)
{
     for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<" "<<arr[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    int arr [3][3];
    input_2d_array(arr,3,3);
    int copy [3][3];
    transpose(arr,3,3,copy);
    cout<<endl;
    display_2d_array(arr,3,3);
    cout<<endl;
    display_2d_array(copy,3,3);
    return 0;
}
