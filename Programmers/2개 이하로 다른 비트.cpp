#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) 
{
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); i++)
    {
        long long tmp = numbers[i];
        if (tmp % 2 == 0) answer.push_back(tmp + 1);
        else
        {
            long long zero = (tmp + 1) & (-tmp);
            long long res = (tmp | zero) & (~(zero >> 1));
            answer.push_back(res);
        }
    }
    return answer;
}
