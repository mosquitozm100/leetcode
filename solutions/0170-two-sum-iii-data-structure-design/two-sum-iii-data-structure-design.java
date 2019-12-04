// Design and implement a TwoSum class. It should support the following operations: add and find.
//
// add - Add the number to an internal data structure.
// find - Find if there exists any pair of numbers which sum is equal to the value.
//
// Example 1:
//
//
// add(1); add(3); add(5);
// find(4) -> true
// find(7) -> false
//
//
// Example 2:
//
//
// add(3); add(1); add(2);
// find(3) -> true
// find(6) -> false
//


class TwoSum {

    /** Initialize your data structure here. */
    HashMap<Integer, Integer> hashmap;
    int cnt;
    public TwoSum() {
        hashmap = new HashMap<>();
    }
    
    /** Add the number to an internal data structure.. */
    public void add(int number) {
        hashmap.put(number, hashmap.containsKey(number) ? hashmap.get(number) + 1 : 1);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public boolean find(int value) {
        for(Map.Entry<Integer, Integer> entry: hashmap.entrySet()){
            int i = entry.getKey();
            int j = value - i;
            if((i == j && hashmap.get(i) >= 2) || (i != j && hashmap.containsKey(j))){
                return true;
            }
        }
        return false;
    }
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * boolean param_2 = obj.find(value);
 */
