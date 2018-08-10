import java.io.*;
import java.lang.*;
import java.util.*;
class GFG
{
    public static < K, V> void printMap(Map<K, V> map)
    {
        Set<Map.Entry<K, V> > s = map.entrySet();
        for(Map.Entry<K, V>  entry : s)
        {
            System.out.println(entry.getKey() + " "+ entry.getValue());
        }
    }


    public void countSort(ArrayList<Integer> A)
    {
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for(int iter = 0; iter < A.size(); iter++)
        {
            int i = A.get(iter);
            Integer val = mp.get(i);
            if(val != null)
            {
                mp.put(i, val+1);
            }
            else
            {
                mp.put(i, 1);
            }
        }

        TreeMap<Integer, Integer> tm = new TreeMap<Integer, Integer>(mp);


        printMap(tm);
    }
}
class TestClass {
    public static void main(String args[] ) throws Exception
    {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        ArrayList<Integer> ai = new ArrayList<Integer>(n);
        for(int iter = 0; iter < n; iter++)
        {
            ai.add(input.nextInt());
        }
        GFG gfg = new GFG();
        gfg.countSort(ai);
    }
}

