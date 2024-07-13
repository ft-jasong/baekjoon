#include <iostream>
#include <algorithm>

using namespace std;

# define INF 987654321

struct Participant {
    int drink_time;
    int rest_time;
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int participant_cnt;
    int max_coke;
    int coke_per_sec;
    int ans;
    Participant participant[1000];

    cin >> participant_cnt >> max_coke >> coke_per_sec;
    for (int i = 0; i < participant_cnt; i++)
        cin >> participant[i].drink_time >> participant[i].rest_time;
    ans = INF;
    for (int i = 0; i < participant_cnt; i++) {
        int max_continous_coke;
        int rest_coke;
        int drink_cnt;
        int time;

        max_continous_coke = participant[i].drink_time * coke_per_sec;
        rest_coke = max_coke % max_continous_coke;
        drink_cnt = max_coke / max_continous_coke;
        if (rest_coke == 0)
            time = drink_cnt * participant[i].drink_time + (drink_cnt - 1) * participant[i].rest_time;
        else {
            time = drink_cnt * (participant[i].drink_time + participant[i].rest_time);
            if (rest_coke % coke_per_sec == 0)
                time += rest_coke / coke_per_sec;
            else
                time += rest_coke / coke_per_sec + 1;
        }
        ans = min(ans, time);
    }
    cout << ans << '\n';
    return (0);
}
