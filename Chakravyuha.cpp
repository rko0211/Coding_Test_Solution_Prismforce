#include <iostream>
#include <vector>
using namespace std;

bool canAbhimanyuCross(long long int i, long long int power, long long int skips_left, long long int recharges_left, const vector<long long int> &enemy_powers, long long int initial_power, vector<vector<vector<int>>> &dp)
{
  // Base case: If Abhimanyu has crossed all circles
  if (i > 10)
  {
    return true;
  }

  // Check if Abhimanyu doesn't have enough power to fight the current enemy
  if (power < enemy_powers[i] && skips_left == 0)
  {
    return false;
  }
  // if (dp[i][skips_left][recharges_left] != -1)
  // {
  //   return dp[i][skips_left][recharges_left];
  // }

  cout << i << " " << skips_left << " " << recharges_left << " " << power << endl;
  bool fight = false;
  bool notfight = false;

  // If Abhimanyu Skip the fight
  if (skips_left > 0)
  {
    notfight = canAbhimanyuCross(i + 1, power, skips_left - 1, recharges_left, enemy_powers, initial_power, dp);
  }
  // IF Abhimanyu DO FIGHT

  // Handle k3 and k7 regenerative logic
  if (i == 2 || i == 6)
  {

    // Enemy regenerates with half of its initial power
    long long int regenerated_power = enemy_powers[i] / 2;

    cout << "SP " << power << " " << regenerated_power << endl;

    // Simulate fight with the regenerated enemy
    if (power >= enemy_powers[i])
    {
      power -= regenerated_power;
      if (recharges_left > 0)
      {
        power = initial_power;
        recharges_left -= 1;
      }
      // Fight enemy `i` and account for its regeneration
      fight = canAbhimanyuCross(i + 1, power - enemy_powers[i], skips_left, recharges_left, enemy_powers, initial_power, dp);
    }
    // Consider recharge if needed after fighting
    if (!fight && recharges_left > 0 && (i + 1) <= 10 && power < enemy_powers[i + 1])
    {
      fight = canAbhimanyuCross(i + 1, initial_power, skips_left, recharges_left - 1, enemy_powers, initial_power, dp);
    }
  }
  else
  {
    // For all other enemies except K3, K7

    if (power >= enemy_powers[i])
    {
      fight = canAbhimanyuCross(i + 1, power - enemy_powers[i], skips_left, recharges_left, enemy_powers, initial_power, dp);
    }

    // Consider recharge if needed after fighting
    if (!fight && recharges_left > 0 && (i + 1) <= 10 && power < enemy_powers[i + 1])
    {
      fight = canAbhimanyuCross(i + 1, initial_power, skips_left, recharges_left - 1, enemy_powers, initial_power, dp);
    }
  }

  return (fight || notfight);
}

int main()
{
  long long int initial_power;
  long long int a;
  long long int b;

  // First Test case
  initial_power = 90; // Example initial power

  vector<long long int> enemy_powers = {10, 20, 30, 40, 5, 6, 7, 8, 9, 10, 11}; // Example enemy powers

  a = 1; // Number of skips

  b = 1; // Number of recharges

  vector<vector<vector<int>>> dp(11, vector<vector<int>>(a + 1, vector<int>(b + 1, -1)));

  bool can_cross1 = canAbhimanyuCross(0, initial_power, a, b, enemy_powers, initial_power, dp);
  cout << "Can Abhimanyu cross the Chakravyuha? " << (can_cross1 ? "Yes" : "No") << endl;

  // 2nd Test Case

  initial_power = 50; // Example initial power

  enemy_powers = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 11}; // Example enemy powers

  a = 2; // Number of skips
  b = 5; // Number of recharges
  vector<vector<vector<int>>> dp1(11, vector<vector<int>>(a + 1, vector<int>(b + 1, -1)));
  bool can_cross2 = canAbhimanyuCross(0, initial_power, a, b, enemy_powers, initial_power, dp1);
  cout << "Can Abhimanyu cross the Chakravyuha? " << (can_cross2 ? "Yes" : "No") << endl;

  return 0;
}
