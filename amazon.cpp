/* To create a min heap which store higheset five scores. Each time I put new element into the heap,
compare it with the first element in the heap. If it is larger, replace the first element with it 
and adjust the heap. */

/* Enter your Big O Analysis here. */
 
/* Enter your code here. */
#include <iostream>

using namespace std;
int cmp ( const void *a , const void *b ) 
{ 
    return *(int *)a - *(int *)b; 
} 

bool h_adjust(int heap[], int h_len) 
{
    int i = 0;
    while(i < h_len && 2 * i + 1 < h_len && 2 * i + 2 < h_len) 
    {
        int min = (heap[2 * i + 2] < heap[2 * i + 1]) ? heap[2 * i + 2] : heap[2 * i + 1];
        int max = (heap[2 * i + 2] > heap[2 * i + 1]) ? heap[2 * i + 2] : heap[2 * i + 1];
        int index = (heap[2 * i + 2] < heap[2 * i + 1]) ? (2 * i + 2) : (2 * i + 1);
        if( heap[i] > max) 
        {
            int tmp = heap[i];
            heap[i] = heap[index];
            heap[index] = tmp;
            i = index;
        }
        else
            break;
    }
}

bool h_sort(int a[], int a_len, int heap[], int h_len) {
    for(int i = 0; i < h_len; i++) 
    {
        heap[i] = a[i];
    }
    qsort(heap, h_len, sizeof(heap[0]), cmp); 
    for(int i = 0; i < h_len; i++)
        cout<<heap[i] << "\t" ;
    cout << endl;
    for(int i = h_len; i < a_len; i++)
    {
        if(a[i] > heap[0]) 
        {
            heap[0] = a[i];
            h_adjust(heap, h_len);
        }
    }
    return true;
}
map  calculateFinalScores (vector results) {
	vector<TestResult>::iterator it = results.begin();
	int a_len = 0;
	set<int> ids ;
	for(; it != results.end(); it++ ) {
		ids.insert(it->studentId);
	}
	a_len = ids.size();
	set<int>::iterator itset;
	for( itset = ids.begin(); itset != ids.end(); itset++) {
		int a* = new int[a_len];
		int i = 0;
		for(it = results.begin(), i = 0; it != results.end(); it++ ) {
			if(it->studentId == *itset) {
				a[i] = it->testScore;
				i++;
			}
		}
		h_sort(a, a_len, h, h_len);
    }
}



/* To create a min heap which store higheset five scores. Each time I put new element into the heap,
compare it with the first element in the heap. If it is larger, replace the first element with it 
and adjust the heap. */

/* The time complexity is n*nlogn. */
 
/* Enter your code here. */
#include <iostream>

using namespace std;
int cmp ( const void *a , const void *b ) 
{ 
    return *(int *)a - *(int *)b; 
} 

bool h_adjust(int heap[], int h_len) 
{
    int i = 0;
    while(i < h_len && 2 * i + 1 < h_len && 2 * i + 2 < h_len) 
    {
        int min = (heap[2 * i + 2] < heap[2 * i + 1]) ? heap[2 * i + 2] : heap[2 * i + 1];
        int max = (heap[2 * i + 2] > heap[2 * i + 1]) ? heap[2 * i + 2] : heap[2 * i + 1];
        int index = (heap[2 * i + 2] < heap[2 * i + 1]) ? (2 * i + 2) : (2 * i + 1);
        if( heap[i] > max) 
        {
            int tmp = heap[i];
            heap[i] = heap[index];
            heap[index] = tmp;
            i = index;
        }
        else
            break;
    }
}

bool h_sort(int a[], int a_len, int heap[], int h_len) {
    for(int i = 0; i < h_len; i++) 
    {
        heap[i] = a[i];
    }
    qsort(heap, h_len, sizeof(heap[0]), cmp); 
    for(int i = 0; i < h_len; i++)
        cout<<heap[i] << "\t" ;
    cout << endl;
    for(int i = h_len; i < a_len; i++)
    {
        if(a[i] > heap[0]) 
        {
            heap[0] = a[i];
            h_adjust(heap, h_len);
        }
    }
    return true;
}
map  calculateFinalScores (vector results) {
vector<TestResult>::iterator it = results.begin();
	int a_len = 0;
	int h_len = 5;
	set<int> ids ;
	for(; it != results.end(); it++ ) {
		ids.insert(it->studentId);
	}
	a_len = ids.size();
	set<int>::iterator itset;
	map<int, float> ret;
	for( itset = ids.begin(); itset != ids.end(); itset++) {
		int a* = new int[a_len];
		int i = 0;
		for(it = results.begin(), i = 0; it != results.end(); it++ ) {
			if(it->studentId == *itset) {
				a[i] = it->testScore;
				i++;
			}
		}
		h_sort(a, a_len, h, h_len);
		float mean = 0;
		for(int k = 0; k < h_len) {
			mean += a[k];
		}
		mean /= 5;
		ret.insert(pair<int, float>(*ids,mean));
	}
	return ret;
}






