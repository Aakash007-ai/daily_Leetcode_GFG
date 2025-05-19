package javaLang.SplitWiseSimplifyDebtAlgorithm;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


//np hard
public class Main {
    public static void main(String args[]){

    }


    public int minTransfer(int [][]transactions){
        Map<Integer,Integer> memberVsBalanceMap = new HashMap<>();
        // compute the overall balance (incoming-outgoing) for each member
        for(int[] txn:transactions){
            int from = txn[0];
            int to = txn[1];
            int amount = txn[2];

            memberVsBalanceMap.put(from, memberVsBalanceMap.getOrDefault(from, 0) - amount);
            memberVsBalanceMap.put(to, memberVsBalanceMap.getOrDefault(to, 0) + amount);
        }
        // put into the balance list
        List<Integer> balances = new ArrayList<>();
        for(int amount: memberVsBalanceMap.values()){
            if(amount != 0){
                balances.add(amount);
            }
        }

        return dfs(balances, 0);
    }


    private int dfs(List<Integer> balanceList , int currentIndex){
        // if we have reached the end of the list return 0
        if(balanceList.size() == 0 || currentIndex >= balanceList.size()) return 0;
        // if the current balance is 0, move to the next index
        if(balanceList.get(currentIndex) == 0) return dfs(balanceList, currentIndex + 1);

        int currentVal = balanceList.get(currentIndex);
        int minTxnCount = Integer.MAX_VALUE;
        for(int txnIndex = currentIndex + 1; txnIndex < balanceList.size(); txnIndex++){
            // if the current balance is positive and the next balance is negative, we can settle the transaction
            int nextVal = balanceList.get(currentIndex);

            if(currentVal * nextVal <0){
                balanceList.set(txnIndex,nextVal+currentVal);
                minTxnCount = Math.min(minTxnCount, 1+ dfs(balanceList, currentIndex+1));

                balanceList.set(txnIndex, nextVal);

                if(currentVal + nextVal == 0){
                    break; // no need to check further as the next balance is already settled
                }
            }
        }

        return minTxnCount;
    }
}

//TC big O(n!)
