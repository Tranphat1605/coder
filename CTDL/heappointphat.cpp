#include <iostream>
using namespace std;
typedef int ele;
typedef struct node
{
    ele data;
} node;
typedef struct heap
{
    int size;
    node *heap_arr;
} heap;
void init(heap &h)
{
    h.size = 0;
    h.heap_arr = NULL;
};
void create_begin_heap(heap &h, node a[], int n)
{
    h.heap_arr = a;
    h.size = n;
}
int right(int i)
{
    return (2 * i + 2);
}
int left(int i)
{
    return (2 * i + 1);
}
int fanode(int i)
{
    return (i - 1) / 2;
}
void show(heap h, int i)
{
    if (i >= 0 && i < h.size)
    {
        cout << " " << h.heap_arr[i].data;
        show(h, left(i));
        show(h, right(i));
    }
};
void showm1c(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void doi(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void showall(heap h)
{
    for (int i = 0; i < h.size / 2; i++)
    {
        cout << endl
             << h.heap_arr[i].data;
        cout << endl
             << "nhanh trai: ";
        show(h, left(i));
        cout << endl
             << "nhanh phai: ";
        show(h, right(i));
    }
}
void max_heap(heap h, int i)
{
    int m = i;
    int l = left(i);
    int r = right(i);
    if (l < h.size && (h.heap_arr[m].data < h.heap_arr[l].data))
        m = l;
    if (r < h.size && h.heap_arr[m].data < h.heap_arr[r].data)
        m = r;
    if (m != i)
    {
        doi(h.heap_arr[m].data, h.heap_arr[i].data);
        max_heap(h, m);
    }
}
void buildmax(heap h)
{
    for (int i = (h.size / 2) - 1; i >= 0; i--)
    {
        max_heap(h, i);
    }
}

void insert(heap &h, ele x)
{
    h.heap_arr[h.size].data = x;
    int i = h.size;
    h.size++;

    while (i > 0 && h.heap_arr[fanode(i)].data < h.heap_arr[i].data)
    {
        doi(h.heap_arr[i].data, h.heap_arr[fanode(i)].data);
        i = fanode(i);
    }
}

void xoa(heap &h, ele x)
{
    int i;
    for (i = 0; i < h.size; i++)
    {
        if (h.heap_arr[i].data == x)
            break;
    }

    if (i < h.size)
    {
        // Đổi phần tử cần xóa với phần tử cuối
        doi(h.heap_arr[i].data, h.heap_arr[h.size - 1].data);
        h.size--;
        if (h.heap_arr[i].data > h.heap_arr[fanode(i)].data)
        {
            while (i > 0 && h.heap_arr[i].data > h.heap_arr[fanode(i)].data)
            {
                doi(h.heap_arr[i].data, h.heap_arr[fanode(i)].data);
                i = fanode(i);
            }
        }
        else
            max_heap(h, i);
    }
    else
        cout << "khong co";
}

void sapxep(heap h)
{
    buildmax(h);
    for (int i = h.size - 1; i >= 0; i--)
    {
        doi(h.heap_arr[i].data, h.heap_arr[0].data);
        h.size = h.size - 1;
        max_heap(h, 0);
    }
}
// void them(heap h, int x)
int main()
{
    node a[20] = {{12}, {15}, {9}, {10}, {7}, {8}, {5}, {6}, {4}, {20}};
    int n = 10;
    heap h;
    create_begin_heap(h, a, n);
    buildmax(h);
    xoa(h,20); cout<<endl;
    sapxep(h);
     for (int i = 0; i < h.size; ++i)
    {
        cout << h.heap_arr[i].data << " ";
    }
    // cout << "Mang goc: ";
    // // show(h, 0);
    // for (int i = 0; i < h.size; ++i)
    // {
    //     cout << h.heap_arr[i].data << " ";
    // }
    // cout << endl;
    // // cout << "\n\nSau khi build max heap:\n";
    // buildmax(h);
    // // show(h, 0);
    // // sapxep(h);
    // for (int i = 0; i < h.size; ++i)
    // {
    //     cout << h.heap_arr[i].data << " ";
    // }
    // insert(h, 30);
    // cout << endl;
    // for (int i = 0; i < h.size; ++i)
    // {
    //     cout << h.heap_arr[i].data << " ";
    // }
    // showall(h);
    // cout << endl;
    // sapxep(h);
    // cout << endl;
    // for (int i = 0; i < h.size; ++i)
    // {
    //     cout << h.heap_arr[i].data << " ";
    // }
    return 0;
}
