#include <iostream>
#include <algorithm>
using namespace std;


int main(void){
    int plug_count, use_count;
    int arr[100];
    int answer = 0;
    int full_check_cnt = 0;
	int plug_status[100] = { 0 };
	bool check[101] = { false };
	
    cin >> plug_count >> use_count;
    for (int i = 0; i < use_count; i++)
		cin >> arr[i];
	
    for (int i = 0; i < use_count; i++) {
        if (full_check_cnt < plug_count) {
            if (!check[arr[i]]) {
                plug_status[full_check_cnt++] = arr[i];
                check[arr[i]] = true;
            }
        }
        else {

            if (!check[arr[i]]) {
                int max_far_index = 0;
                int change_idx = 0;
                for (int j = 0; j < plug_count; j++) {
                    int tmp_idx = -1;
                    for (int z = i + 1; z < use_count; z++) {
                        if (plug_status[j] == arr[z]) {
                            tmp_idx = z;
                            break;
                        }
                    }
                    if (tmp_idx < 0) {
                        change_idx = j;
                        break;
                    }
                    else {
                        if (max_far_index < tmp_idx) {
                            max_far_index = tmp_idx;
                            change_idx = j;
                        }
                    }
                }
                check[plug_status[change_idx]] = false;
                answer++;
                plug_status[change_idx] = arr[i];
                check[plug_status[change_idx]] = true;
            }
        }
    }
    cout << answer;
    return 0;
}
