public abstract class ThreeSum {
    public abstract int T_sum(int[] A);
}

class Three_Sum extends ThreeSum {

    public static void sort(int[] a, int l, int r) {
        if (l == r) return;
        int m = (l+r) >> 1;
        sort(a, l, m); sort(a, m+1, r);
        int pointer_lhs = l, pointer_rhs = m+1;
        int[] tmp = new int[r-l+1];
        for (int i = 0; i < r-l+1; i++) {
            if (pointer_lhs == m+1) {
                tmp[i] = a[pointer_rhs];
                pointer_rhs++;
            }
            else if (pointer_rhs == r+1) {
                tmp[i] = a[pointer_lhs];
                pointer_lhs++;
            }
            else {
                if (a[pointer_lhs] < a[pointer_rhs]) {
                    tmp[i] = a[pointer_lhs];
                    pointer_lhs++;
                }
                else {
                    tmp[i] = a[pointer_rhs];
                    pointer_rhs++;
                }
            }
        }
        for (int i = 0; i < r-l+1; i++) a[l+i] = tmp[i];
    }

    public int T_sum(int[] A) {
        int[] nums = A;
        int n = nums.length;
        sort(nums, 0, nums.length-1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int k = n - 1;
            int target = -nums[i];
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                while (j < k && nums[j] + nums[k] > target)
                    k--;
                if (j == k)
                    break;
                if (nums[j] + nums[k] == target)
                    ans++;
            }
        }
        return ans;
    }
}

class Main {
    public static void main(String[] args) {
        int[] input = new int[] { -1, 1, 2, 4, 8, -3 };
        Three_Sum three_Sum = new Three_Sum();
        System.out.println(three_Sum.T_sum(input));
    }
}
