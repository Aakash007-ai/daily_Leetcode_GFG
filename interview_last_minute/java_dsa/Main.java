import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val){
        this.val = val;
    }
}

public class Main{
    public static void main(String[] args) {

    }

    public int[] twoSum(int[] nums, int target){
        // via hashmap 
        Set<Integer> hashSet = new HashSet<>();
        Map<Integer,Integer> hashMap = new HashMap<>();

        for(int i=0;i<nums.length;i++){
            int need = target - nums[i];
            if(hashMap.containsKey(need)){
                return new int[]{hashMap.get(nums[i]),i};
            }
            hashMap.put(nums[i],i);
        }
        return new int[]{};
    }

    public boolean containDuplicate(int[] nums){
        HashSet<Integer> set = new HashSet<>();

        for(int num: nums){
            if(set.contains(num)){
                return true;
            }
            set.add(num);
        }
        return false;
    }

    // by default using recursion -> dp -> knapsack
    public int subarraySum(int[] nums, int k){
        Map<Integer,Integer> map = new HashMap<>();
        map.put(0,1);

        int sum = 0,count = 0;
        for(int num:nums){
            sum += num;

            if(map.containsKey(sum-k)){
                count+=map.get(sum-k);
            }

            map.put(sum, map.getOrDefault(sum,0)+1);
        }
        return count;
    }


}