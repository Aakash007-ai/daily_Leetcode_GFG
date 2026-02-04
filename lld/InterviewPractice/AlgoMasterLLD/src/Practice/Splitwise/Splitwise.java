package Practice.Splitwise;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.List;

public class Splitwise {
    public int minTransaction(int [][] tranasactions){
        Map<Integer,Integer> membserBalance = new HashMap<>();
        for(int[] txn : tranasactions){
            int from = txn[0];
            int to = txn[1];
            int amount = txn[3];
            // A has to give B x amount
            // incoming - outgoing
            membserBalance.put(from, membserBalance.getOrDefault(from, 0)-amount);
            membserBalance.put(from,membserBalance.getOrDefault(to,0)+amount);
        }

        // now we have final balance for each one
        List<Integer> balances = new ArrayList<>();
        for(int amount : membserBalance.values()){
            if(amount!= 0) balances.add(amount);
        }
        return dfs(balances,0);
    }

    private int dfs(List<Integer> balanceList , int currentIndex){
        if(balanceList.size() == 0 || currentIndex >= balanceList.size()) return 0;

        if(balanceList.get(currentIndex) == 0) return dfs(balanceList, currentIndex+1);

        int currentValue = balanceList.get(currentIndex);
        int minTxnCount = Integer.MAX_VALUE;

        for(int txnIndex = currentIndex+1; txnIndex<balanceList.size();txnIndex++ ){
            int nextValue = balanceList.get(txnIndex);

            if(currentValue*nextValue <0){
                balanceList.set(txnIndex, currentIndex+nextValue);
                minTxnCount = Math.min(minTxnCount, 1+dfs(balanceList, currentIndex+1));
                balanceList.set(txnIndex,nextValue);

                if(currentValue + nextValue == 0){
                    break;
                }
            }
        }
        return minTxnCount;
    }
}
