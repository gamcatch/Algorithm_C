#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int bs_upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // not n-1
    while (l < h) {
        int mid = l + (h-1) /2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            if (mid + 1 == h){
                break;
            }
            h = mid;
        }
    }
    return l;
}

int bs_lower_bound(int a[], int n, int x) {
    int l =0;
    int h = n;
    while(l < h) {
        int mid = l + (h - 1)/2;

        if (x <= a[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }

    }
    return l;
}

int main(void) {
    int a[8] = {1, 2, 2 , 2, 3, 3, 4, 7};

    printf("\n%d",bs_lower_bound(a, 8, 2));
    printf("\n%d",bs_upper_bound(a, 8, 2));

    vector<int> data = {1, 2, 2 , 2, 3, 3, 4, 7};
    printf("\n%d",distance(data.begin(), lower_bound(data.begin(), data.end(), 2)));

    printf("\n%d",distance(data.begin(), upper_bound(data.begin(), data.end(), 2)));
    return 0;
}