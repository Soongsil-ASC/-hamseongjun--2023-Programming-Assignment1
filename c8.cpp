
Program 8.1:Converting a string into a non-negative integer
====================================
unsigned int StringToInt(string s)
{// Convert s into a nonnegative int that depends on all characters of s.
  int length = (int) s.length();   // number of characters in s
  unsigned int answer = 0;
  if (length % 2 == 1)
  {// length is odd
    answer = s.at(length - 1);
    length--;
  }
  
  // length is now even
  for (int i = 0; i < length; i += 2)
  {// do two characters at a time
    answer += s.at(i);
    answer += ((int) s.at(i + 1)) << 8;
  }
  return answer;
}
====================================





Program 8.2:The specialization hash<string>
====================================
template<>
class hash<string> {
public:
  size_t operator()(const string theKey) const
  {// Convert theKey to a nonnegative integer.
    unsigned long hashValue = 0; 
    int length = (int) theKey.length();
    for (int i = 0; i < length; i++)
      hashValue = 5 * hashValue + theKey.at(i);
    
    return size_t(hashValue);
  }
};
====================================




Program 8.3:SHA algorithm
====================================
Step 1: 
Preprocess the message so that its length is q * 512 bits for some integer q.  The preprocessing may entail adding a string of zeroes to the end of the message.

Step 2:
Initialize the 160-bit output buffer OB, which comprises five 32-bit
registers A, B, C, D, and E,  with A =  67452301, B = efcdab89, C = 98badcfe,
D = 10325476, E = c3d2e1f0 (all values are in hexadecimal).

Step 3:
   for (int i = 1; i <= q; i++) {
    Let B sub i = ith block of 512 bits of the message;
    OB = F(OB , B sub i );
  }

Step 4:Output OB.
====================================





Program 8.4:Linear probing
====================================
template <class K, class E>
pair<K,E>* LinearProbing<K,E>::Get(const K& k)
{// Search the linear probing hash table ht (each bucket has exactly one slot) for k.
// If a pair with this key is found, return a pointer to this pair; otherwise, return 0.
  int i = h(k);   // home bucket
  int j;
  for (j = i; ht[j] && ht[j]->first != k;) {
    j = (j + 1) % b;                 // treat the table as circular
    if (j == i) return 0;// back to start point
  }
  if (ht[j]->first == k) return ht[j];
  return 0;
}
====================================






Program 8.5:Chain search
====================================
template <class K, class E>
pair<K,E>* Chaining<K,E>::Get(const K& k)
{// Search the chained hash table ht for k.
// If a pair with this key is found, return a pointer to this pair; otherwise, return 0.
  int i = h(k);   //  home bucket
  // search the chain ht[i]
  for (ChainNode<pair<K,E> >* current = ht[i]; current; 
  current = current->link)
    if (current->data.first == k) return &current->data;
  return 0;
}
====================================




Program 8.6:Searching a directoryless hash table
====================================
if (h(k,r) < q) search the chain that begins at bucket h(k,r+1);
else search the chain that begins at bucket h(k,r);
====================================


