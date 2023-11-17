<ol><li>if you encounter any of the problem randomly, just think of recursion</li></ol>
<ul>
<li><h3>0-1 knapsack</h3><p>we are given with a weight, an array of weight and an value, find the maximum value we can take to fill bag of weight weight</p></li><li>
<h3>subset sum partition</h3><p>we are given an array and a sum and have to find whether the sum is present or not in array.<br>
we are given with choice as which element to choose or not to choose so thats a dp problem<br>
so using kanpsack approach<br>
Bottom up approach create an 2d array with sum and array size +1, then for sum=0 whatever size of array we retrun true and if sum is something but size of array is 0 we return false</p></li>
<li><h3>
equal sum partition</h3>
<p>
we have to find whether a given array can be divided into equal partition

approach in order to get partition we get sum of all elements and check whether it is rvrn or not as only even sum can be divided
if it is even then find subset sum partition</p>

</li>
<li><h3>count number of subset sum with given sum</h3><p></p></li>

<li><h3> minimum subset sum difference<h3>
