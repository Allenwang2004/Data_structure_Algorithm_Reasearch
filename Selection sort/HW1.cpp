//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW1.h"
#include <time.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define SWAP(x,y,t) (t=x,x=y,y=t)
int data[100000];
int original_data[100000];
int Leftdata[100000];   //用在Merge Sort
int Rightdata[100000];
int sum1[1000];   //這邊是用在最後輸出圖表結果的地方
int sum2[1000];
int sum3[1000];
int sum4[1000];

int n;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
void SelectionSort(int data[], int n)
{
	int i,j,temp,min;
		for(i=0;i<n;i++)
		{
			min=i;
			for(j=i+1;j<n;j++)
			{
				if(data[j]<data[min])
				{
					min = j;
				}
			}
			temp = data[i];
			data[i]=data[min];
            data[min]=temp;
        }

}

void BubbleSort(int data[],int n)
{
	int i,j,temp;
		for (i=n-1;i>=0;i--)
		{
			for(j=1;j<i+1;j++)
			{
				if(data[j-1]>data[j])
					SWAP(data[j-1],data[j],temp);
			}
        }
}

int BinarySearch(int data[],int n,int target)
{
	int low=0;
	int upper = n-1;
	while(low<=upper)
	{
		int mid = (low+upper)/2;
		if(data[mid]<target)
			low=mid+1;
		else if(data[mid]>target)
			upper=mid-1;
		else
			return mid;
	}
}

void Merge(int data[], int front, int mid, int end)
{
	for(int i=front;i<=mid;i++)
	{
		Leftdata[i]=data[i];
		Rightdata[i]=data[i+mid];
	}
	Leftdata[mid+1]=1000000;
    Rightdata[mid+1]=1000000;
	int left=0;
	int right=0;
	for (int i = front; i <= end; i++)
	{
		if (Leftdata[left] <= Rightdata[right] )  //比較左右兩邊 放入小的
		{
			data[i] = Leftdata[i];
			left++;
		}
		else
		{
			data[i] = Rightdata[i];
			right++;
		}
    }
}

void MergeSort(int data[], int front, int end)
{
	if (front < end)
	{
		int mid = (front+end)/2;
		MergeSort(data, front, mid);
		MergeSort(data, mid+1, end);
		Merge(data, front, mid, end);
	}
}

int Partition(int data[], int front, int end)
{
	int pivot = data[end];
	int temp;
	int i = front -1;
	for (int j = front; j < end; j++)
	{
		if (data[j] < pivot)
		{
			i++;
			SWAP(data[i],data[j],temp);
		}
	}
	i++;
	SWAP(data[i],data[end],temp);
	return i;
}

void QuickSort(int data[], int front, int end)
{
	if (front < end)
	{
        int pivot = Partition(data, front, end);
		QuickSort(data, front, pivot - 1);
		QuickSort(data, pivot + 1, end);
    }
}


void printdata(int data[],int n,int flag)
{
	int i;
		if(flag==1)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo1->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==2)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo2->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==3)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo3->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==5)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo5->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}
		else if(flag==6)
		{
			for(i=0;i<n;i++)
			{
				Form1->Memo6->Lines->Add("data["+IntToStr(i)+"] = "+IntToStr(data[i]));
			}
		}

}

void Checkdata(int data[],int n,int flag)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(data[i]>data[i+1])
		{
			break;
        }
    }
	if(i==n-1)
	{
		if(flag==2)
			Form1->Memo2->Lines->Add("Correctly Sorted.");
		else if(flag==3)
			Form1->Memo3->Lines->Add("Correctly Sorted.");
		else if(flag==5)
			Form1->Memo5->Lines->Add("Correctly Sorted.");
		else
			Form1->Memo6->Lines->Add("Correctly Sorted.");
	}
	else
    {
		if(flag==2)
			Form1->Memo2->Lines->Add("Not Sorted.");
		else if(flag==3)
			Form1->Memo3->Lines->Add("Not Sorted.");
		else if(flag==5)
			Form1->Memo5->Lines->Add("Not Sorted.");
		else
			Form1->Memo6->Lines->Add("Not Sorted.");
	}

}

void RandData(int original_data[],int n ,int range)
{
	for(int i=0;i<n;i++)
	{
		original_data[i] = rand()% range+1;
	}
}

void PlusData(int original_data[],int n ,int range,int step)    //這個是用在新增data在原陣列的後面
{
	for(int i=n+1;i<n+step;i++)
	{
		original_data[i] = rand()% range+1;
	}
}

void getData(int data[],int original_data[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		data[i]= original_data[i];
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int repeation = StrToInt(Edit4->Text);
	int sum=0;
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	int range =StrToInt(Edit2->Text);
		srand(time(NULL));
        clock_t t_begin,t_end;
		t_begin = clock();
		RandData(original_data,n,range);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(original_data,n,1);
		sum=sum+(t_end-t_begin);
	for(int i=0;i<repeation;i++)
	{
			srand(time(NULL));
		clock_t t_begin,t_end;
			t_begin = clock();
			PlusData(original_data,n,range,step);//這個是用在新增data在原陣列的後面
			t_end = clock();
			if(CheckBox1->Checked)
				printdata(original_data,n,1);
		n= n+step;
		sum=sum+(t_end-t_begin);
	}
	Form1->Memo1->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum)/CLOCKS_PER_SEC));

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{   int repeation =StrToInt(Edit4->Text);
	for(int i=0;i<1000;i++)
	{
		sum1[i]=0;
	}
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		SelectionSort(data,n);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,2);
		if(CheckBox2->Checked)
			Checkdata(data,n,2);
		sum1[i+1] =  sum1[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo2->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum1[i])/CLOCKS_PER_SEC));
	}
	//這樣就可以一次得到所有數據
}
//--------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{   int repeation =StrToInt(Edit4->Text);
	for(int i=0;i<1000;i++)
	{
		sum2[i]=0;
    }
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
    for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		BubbleSort(data,n);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,3);
		if(CheckBox2->Checked)
			Checkdata(data,n,3);
		sum2[i+1] =  sum2[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo3->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum2[i])/CLOCKS_PER_SEC));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{ clock_t t_begin,t_end;
	t_begin = clock();
	int target = StrToInt(Edit3->Text);
	int success = -1;
	success = BinarySearch(data, n ,target);
	if(success >=0 && success<n)
		Memo4->Lines->Add(IntToStr(target)+" has been found");
	else
		Memo4->Lines->Add(IntToStr(target)+" has not been found");
	t_end = clock();
	Form1->Memo4->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(t_end-t_begin)/CLOCKS_PER_SEC));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{   int repeation =StrToInt(Edit4->Text);
	for(int i=0;i<1000;i++)
	{
		sum3[i]=0;
	}
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		MergeSort(data,0,n-1);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,5);
		if(CheckBox2->Checked)
			Checkdata(data,n,5);
		sum3[i+1] =  sum3[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo5->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum3[i])/CLOCKS_PER_SEC));
	}

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int repeation =StrToInt(Edit4->Text);
	for(int i=0;i<1000;i++)
	{
		sum4[i]=0;
	}
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for(int i=0;i<=repeation;i++)  //這邊是小於等於 因為前面沒有跑過一次
	{
	clock_t t_begin,t_end;
		t_begin = clock();
		getData(data,original_data,n);
		QuickSort(data,0,n-1);
		t_end = clock();
		if(CheckBox1->Checked)
			printdata(data,n,6);
		if(CheckBox2->Checked)
			Checkdata(data,n,6);
		sum4[i+1] =  sum4[i]+(t_end-t_begin);
		n=n+step;
	}
	for(int i=1;i<=repeation+1;i++)      //這邊則是要再加一次
	{
	  Form1->Memo6->Lines->Add("CPU time(sec.) = "+FloatToStr((float)(sum4[i])/CLOCKS_PER_SEC));
	}

}
//---------------------------------------------------------------------------

//底下是各個圖表

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Compare of CPU time");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=4;i++)
	{
		TLineSeries *Series=new TLineSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}
	int repeation =StrToInt(Edit4->Text);
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for (int i=1; i<=repeation+1; i++)
	{
		Chart1->Series[0]->Title = "Insertion Sort";
		Chart1->Series[1]->Title = "Bubble Sort";
		Chart1->Series[2]->Title = "Merge Sort";
		Chart1->Series[3]->Title = "Quick Sort";
		Chart1->Series[0]->Add( sum1[i] , n+step*(i-1) , clBlue );
		Chart1->Series[1]->Add( sum2[i] , n+step*(i-1) , clYellow );
		Chart1->Series[2]->Add( sum3[i] , n+step*(i-1) , clRed );
		Chart1->Series[3]->Add( sum4[i] , n+step*(i-1) , clGreen );
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
	Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Compare of CPU time");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=4;i++)
	{
		TLineSeries *Series=new TLineSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}
	int repeation =StrToInt(Edit4->Text);
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for (int i=1; i<=repeation+1; i++)
	{
		Chart1->Series[0]->Title = "Insertion Sort";
		Chart1->Series[1]->Title = "Bubble Sort";
		Chart1->Series[2]->Title = "Merge Sort";
		Chart1->Series[3]->Title = "Quick Sort";
		Chart1->Series[0]->Add( sum1[i] , n+step*(i-1) , clBlue );
		Chart1->Series[1]->Add( sum2[i] , n+step*(i-1) , clYellow );
		Chart1->Series[2]->Add( sum3[i] , n+step*(i-1) , clRed );
		Chart1->Series[3]->Add( sum4[i] , n+step*(i-1) , clGreen );
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
	Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Compare of CPU time");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=4;i++)
	{
		TBarSeries *Series=new TBarSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}
	int repeation =StrToInt(Edit4->Text);
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for (int i=1; i<=repeation+1; i++)
	{
		Chart1->Series[0]->Title = "Insertion Sort";
		Chart1->Series[1]->Title = "Bubble Sort";
		Chart1->Series[2]->Title = "Merge Sort";
		Chart1->Series[3]->Title = "Quick Sort";
		Chart1->Series[0]->Add( sum1[i] , n+step*(i-1) , clBlue );
		Chart1->Series[1]->Add( sum2[i] , n+step*(i-1) , clYellow );
		Chart1->Series[2]->Add( sum3[i] , n+step*(i-1) , clRed );
		Chart1->Series[3]->Add( sum4[i] , n+step*(i-1) , clGreen );
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
	Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Compare of CPU time");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=4;i++)
	{
		TAreaSeries *Series=new TAreaSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}
	int repeation =StrToInt(Edit4->Text);
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for (int i=1; i<=repeation+1; i++)
	{
		Chart1->Series[0]->Title = "Insertion Sort";
		Chart1->Series[1]->Title = "Bubble Sort";
		Chart1->Series[2]->Title = "Merge Sort";
		Chart1->Series[3]->Title = "Quick Sort";
		Chart1->Series[0]->Add( sum1[i] , n+step*(i-1) , clBlue );
		Chart1->Series[1]->Add( sum2[i] , n+step*(i-1) , clYellow );
		Chart1->Series[2]->Add( sum3[i] , n+step*(i-1) , clRed );
		Chart1->Series[3]->Add( sum4[i] , n+step*(i-1) , clGreen );
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
	Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Compare of CPU time");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=4;i++)
	{
		TPointSeries *Series=new TPointSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}
	int repeation =StrToInt(Edit4->Text);
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for (int i=1; i<=repeation+1; i++)
	{
		Chart1->Series[0]->Title = "Insertion Sort";
		Chart1->Series[1]->Title = "Bubble Sort";
		Chart1->Series[2]->Title = "Merge Sort";
		Chart1->Series[3]->Title = "Quick Sort";
		Chart1->Series[0]->Add( sum1[i] , n+step*(i-1) , clBlue );
		Chart1->Series[1]->Add( sum2[i] , n+step*(i-1) , clYellow );
		Chart1->Series[2]->Add( sum3[i] , n+step*(i-1) , clRed );
		Chart1->Series[3]->Add( sum4[i] , n+step*(i-1) , clGreen );
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
	Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Compare of CPU time");
	Chart1->BottomAxis->Title->Caption = "Data";
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=4;i++)
	{
		TPieSeries *Series=new TPieSeries(Chart1);
		Series->ParentChart=Chart1;
		Chart1->AddSeries(Series);
	}
	int repeation =StrToInt(Edit4->Text);
	int step = StrToInt(Edit5->Text);
	n= StrToInt(Edit1->Text);
	for (int i=1; i<=repeation+1; i++)
	{
		Chart1->Series[0]->Title = "Insertion Sort";
		Chart1->Series[1]->Title = "Bubble Sort";
		Chart1->Series[2]->Title = "Merge Sort";
		Chart1->Series[3]->Title = "Quick Sort";
		Chart1->Series[0]->Add( sum1[i] , n+step*(i-1) , clBlue );
		Chart1->Series[1]->Add( sum2[i] , n+step*(i-1) , clYellow );
		Chart1->Series[2]->Add( sum3[i] , n+step*(i-1) , clRed );
		Chart1->Series[3]->Add( sum4[i] , n+step*(i-1) , clGreen );
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Chart1->RemoveAllSeries();    //清除所有圖表
}
//---------------------------------------------------------------------------


