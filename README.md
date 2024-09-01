 <h1 align="center">
  <strong> Coding_Test_Solution_Prismforce</strong>
</h1>


## Table of Contents
1. [Problem Statement](#problem-statement)
2. [Algorithm Explanation](#algorithm-explanation)
3. [Example Test Cases](#example-test-cases)
4. [Algorithm Performance](#algorithm-performance)
5. [How to Run the Code](#how-to-run-the-code)

## Problem Statement
- Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by different enemies. Abhimanyu is located in the innermost circle and has to cross all the 11 circles to reach Pandavas army back.
 
- Given: 
    -  Each circle is guarded by different enemy where enemy is equipped with k1, k2……k11 powers Abhmanyu start from the innermost circle with p power Abhimanyu has a boon to skip fighting enemy a times 
    - Abhmanyu can recharge himself with power b times 
    - Battling in each circle will result in loss of the same power from Abhimanyu as the enemy. 
    - If Abhmanyu enter the circle with energy less than the respective enemy, he will lose the battle
    -  k3 and k7 enemies are endured with power to regenerate themselves once with half of their initial power and can attack Abhimanyu from behind if he is battling in iteratively next circle
      

## Algorithm Explanation

1. **Initialization**: Start with Abhimanyu's initial power, the available number of skips and recharge operations, and the list of different enemy power levels.

## Overview

The `canAbhimanyuCross` function is designed to determine if Abhimanyu can successfully navigate through a series of 11 circles, each guarded by an enemy with a specific power level. The function takes into account Abhimanyu's initial power, the power levels of the enemies, and the number of skips and recharges available to him.

## Algorithm Steps
### 1. Main Function (`main`)
- Declare and Initialize Variables:

  -  `initial_power`: Stores Abhimanyu's initial power.
   - `skipLeft`: The number of times Abhimanyu can skip battles.
   -  `rechargeLeft`: The number of times Abhimanyu can recharge his power.
   -  `enemy_powers`: A vector storing the power of each enemy in the 11 circles.
  
### 2.  `canAbhimanyuCross` Function

 #### Parameters
- **Circle Number (`i`)**: Circle number on which Abhimanyu present.
- **Initial Power (`initialPower`)**: Abhimanyu's starting power level.
- **Enemy Powers (`enemyPowers`)**: A list of power levels for each enemy in the 11 circles.
- **Skip (`skipLeft`)**: The number of times Abhimanyu can skip a battle.
- **Recharge (`rechargeLeft`)**: The number of times Abhimanyu can recharge his power to the initial level.

  
 **I. Initialize Variables**

- **`no_Of_Enemy_Having_Power_More_Than_Abhimanyu`**: This variable counts how many enemies have power levels greater than Abhimanyu's initial power. It is used to determine if Abhimanyu can skip enough battles to cross all circles.

**II. Count Stronger Enemies**

- The function first loops through the `enemyPowers` array to count how many enemies have power greater than `initialPower`. This helps assess whether it's feasible for Abhimanyu to cross based on the available skips.

**III. Check Skip Feasibility**

- After counting stronger enemies, the function checks if the number of skips (`skipLeft`) is less than `no_Of_Enemy_Having_Power_More_Than_Abhimanyu`. If so, it returns `false` since it's impossible for Abhimanyu to bypass all stronger enemies.

**IV. Traverse Each Circle:**

    Iterate Over Each Circle: Loop through each circle's index i from 0 to 10.

    Special Enemies (K3 and K7 at indices 2 and 6):
        Case: Enemy Power > Initial Power:

            If the current enemyPowers[i] is greater than initialPower:

                Check Skipping Availability: If skipLeft is at least 2:
                    Decrement skipLeft by 2 to skip the current and next circle.
                    Increment i by 1 to move past the next circle.

                Skipping Not Available: If skipLeft is less than 2, return false because Abhimanyu can't skip two circles.

        Case: Enemy Power ≤ Initial Power:

            If the current enemyPowers[i] is less than or equal to initialPower:

                Check Current Power Against Enemy Power:

                    If currentPower is less than the enemyPowers[i]:

                        Recharge Option: If rechargeLeft is available, recharge to initialPower and decrement rechargeLeft by 1.

                        Skipping Option: If rechargeLeft is not available but skipLeft is at least 2, decrement skipLeft by 2 and skip the next circle.

                        No Options Left: If neither option is available, return false.

                Regeneration of Special Enemy:

                    Compute the regenerated power of the special enemy (Regeneratedpower_of_special_enemy = enemyPowers[i] / 2).
                    Decrease currentPower by this regenerated power.

                    Post-Regeneration Check:

                        If currentPower is still less than the enemyPowers[i]:

                            Recharge Option: If rechargeLeft is available, recharge and decrement rechargeLeft.

                            Skipping Option: If rechargeLeft is not available but skipLeft is at least 2, adjust currentPower by adding back the regenerated power, decrement skipLeft by 2, and increment i to skip the next circle.

                            No Options Left: If neither option is available, return false.

                After considering all options, reduce currentPower by the enemyPowers[i].

    Normal Enemies:

        Case: Enemy Power > Initial Power:

            If enemyPowers[i] is greater than initialPower:

                Skip if Possible: If skipLeft is available, decrement skipLeft by 1.

                Cannot Skip: If skipLeft is 0, return false.

        Case: Enemy Power ≤ Initial Power:

            If enemyPowers[i] is less than or equal to initialPower:

                Check Current Power:

                    If currentPower is less than the enemyPowers[i]:

                        Recharge Option: If rechargeLeft is available, recharge to initialPower and decrement rechargeLeft by 1.

                        Skipping Option: If rechargeLeft is not available but skipLeft is available, decrement skipLeft by 1.

                        No Options Left: If neither option is available, return false.

                After considering all options, reduce currentPower by the enemyPowers[i].

**V. Final Check:**

    Completion Check: If all circles are processed without returning false, then Abhimanyu can cross all circles.

    Result: Return true.


## Example Test Cases

### Test Case 1

- **Initial Power**: 50
- **Enemy Powers**: {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 11}
- **Skips**: 2
- **Recharges**: 5

**Result**: Can Abhimanyu cross the Chakravyuha?  No.

### Test Case 2

- **Initial Power**: 50
- **Enemy Powers**: {10, 10, 60, 20, 20, 10, 70, 10, 20, 10, 11}
- **Skips**: 4
- **Recharges**: 10

**Result**: Can Abhimanyu cross the Chakravyuha?  Yes.


## Output Image
![test](https://github.com/user-attachments/assets/afe225f0-cfe5-4285-a5e0-0db7115207d8)

## Algorithm Performance
### Time Complexity: O(1), as the algorithm performs a constant number of iterations (11)

### Space Complexity: O(1), as no additional auxiliary space is required


## Conclusion

The main function `canAbhimanyuCross` accepts parameters to define the initial power, available skips, available recharges, and enemy powers. It returns `true` if Abhimanyu can cross all circles or `false` otherwise. The `canAbhimanyuCross` function  evaluates Abhimanyu's ability to navigate through a challenging series of enemies by effectively managing his resources (skips and recharges) while accounting for special cases and enemy regenerations. The function uses strategic checks and balances to ensure that Abhimanyu has the best chance of success.


## How to Run the Code

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/rko0211/Coding_Test_Solution_Prismforce.git
   cd Coding_Test_Solution_Prismforce
