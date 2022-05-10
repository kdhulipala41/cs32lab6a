#include "WordCount.h"
#include <random>
#include <string>
#include <iostream>
#include "tddFuncs.h"
using namespace std;


std::string random_string(std::string::size_type length)
{
    static auto& chrs = "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

    std::string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
}


int main() {
  cout << "\n\nTesting class WordCount..." << endl; 
  WordCount wc3 = WordCount();

  cout << "Adding bigText now. \n\n";
  wc3.addAllWords("As with the birth of art came the\nbirth of the critic, so with the birth of\trecorded history came the birth\tof the historical revisionist.\nFrom the days of Herodotus, critics like Thucydides have questioned the' faithfulness of historical\n accounts, have doubted the\n\n  \timpartiality of other historians\t, and have brought about the assimilation \t of those who write history into the very\tfabric of history itself\n.\t It is in precisely this context that we must analyze events as      fraught with controversy as the Westward\n Expansion \nand\n the \nconquest\n of\t the\t New \tWorld  \n;\n the reporting and coverage of these histories are just as important as the histories themselves, for they influenced the decisions of historical players and shaped public sentiments, the vestiges of which are found even in the present day."); 
  cout << "\n\n";
  cout << "wordcount is: " << wc3.getTotalWords() << "\n\n";
  cout << "unique wordcount is: " << wc3.getNumUniqueWords() << "\n\n\n\n\n";
  cout << "-------------NOW DUMPING BY LEXICO-------------\n";
  wc3.dumpWordsSortedByWord(std::cout);
  cout << "\n\n\n";
  cout << "-------------NOW DUMPING BY COUNTS-------------\n";
  wc3.dumpWordsSortedByOccurence(std::cout);
  cout << "\n\n\n";




/*  cout << "\n1ofO- is: " << wc3.makeValidWord("1ofO-") << "\n\n";
  cout << "\nOFO is: " << wc3.makeValidWord("OFO") << "\n\n";
  cout << "\n^Ofo2 is: " << wc3.makeValidWord("^Ofo2") << "\n\n";
  cout << "\nOfo is: " << wc3.makeValidWord("Ofo") << "\n\n";
  cout << "\n--$$-- is: " << wc3.makeValidWord("--$$--") << "\n\n";
  std::string empt = "";
  cout << "length of empty is: " << empt.length() << endl; 
  cout << "adding --$$--: " << wc3.incrWordCount("--$$--") << endl;
  cout << "total wordcount: " << wc3.getTotalWords() << "\n\n";
  cout << "adding --$$--: " << wc3.incrWordCount("--$$--") << endl;
  cout << "total wordcount: " << wc3.getTotalWords() << "\n\n";
*/


 /* cout << wc3.getTotalWords() << "\n\n";
  cout << wc3.getNumUniqueWords() << "\n\n";
  cout << "adding 'isn't': " << wc3.incrWordCount("isn't") << "\n\n";
  cout << "adding $#'isn't--: " << wc3.incrWordCount("$#'isn't--") << "\n\n";
  cout << "adding $#'isn't--: " << wc3.incrWordCount("$#'isn't--") << "\n\n";
  cout << wc3.incrWordCount("n'ist") << "\n\n";
  cout << wc3.getTotalWords() << "\n\n";
  cout << wc3.getNumUniqueWords() << "\n\n";
  cout << wc3.getWordCount("isn't") << "\n\n";
  cout << wc3.getNumUniqueWords() << "\n\n";
  cout << wc3.getWordCount("isn't") << "\n\n";*/


  /*cout << "hash of heehoo is: " << instance.hash("heehoo") << endl;
  cout << "hash of eehooh is: " << instance.hash("eehooh") << endl;
  cout << "hash of gainly is: " << instance.hash("gainly") << endl;
  cout << "hash of laying is: " << instance.hash("laying") << endl;


  cout << "\n# of total words: " << instance.getTotalWords() << endl;
  cout << "# of unique words: " << instance.getNumUniqueWords() << endl;
  cout << "# of 'cook's: " << instance.getWordCount("cook") << endl;

  
  
  std::string longWord = "";
  for (int i=0; i<641; i++) {
	 longWord += random_string(100);
  }
  cout << "done generating longWord" << endl; 


  cout << "now adding longWord head: " << longWord.substr(0,10) << "... : " << instance.incrWordCount(longWord) << endl;
  cout << "now adding 'hello/nworld/nherearesome/nnewlines' : " << instance.incrWordCount("hello\nworld\nherearesome\nnewlines") << endl;
  cout << "\n# of total words: " << instance.getTotalWords() << endl;
  cout << "# of unique words: " << instance.getNumUniqueWords() << endl;
  cout << "# of longWords: " << instance.getWordCount(longWord) << endl;
  cout << "# of hello/nworld/nherearesome/nnewlines's: " << instance.getWordCount("hello\nworld\nherearesome\nnewlines") << endl;
  cout << "now removing longWord: " << instance.decrWordCount(longWord) << endl;
  cout << "now removing helloworldnosnense: " << instance.decrWordCount("hello\nworld\nherearesome\nnewlines") << endl;
  cout << "\n# of total words: " << instance.getTotalWords() << endl;
  cout << "# of unique words: " << instance.getNumUniqueWords() << endl;
  cout << "# of longWords: " << instance.getWordCount(longWord) << "\n\n";

*/

 //cout << "Makevalid('aRT-*) is: " << instance.makeValidWord("'aRT-*") << "\n\n";


  
  /*cout << "now removing '': " << instance.decrWordCount("") << endl;
  cout << "now removing heehoo" << endl;
  cout << instance.decrWordCount("heehoo") << endl;

  cout << "# of 'cook's: " << instance.getWordCount("cook") << endl;
  cout << "# of unique words: " << instance.getNumUniqueWords() << endl;
  cout << "# of total words: " << instance.getTotalWords() << endl;

  cout << "now adding '': " << instance.incrWordCount("") << endl;

  cout << "# of ''s: " << instance.getWordCount("") << endl;
  cout << "# of unique words: " << instance.getNumUniqueWords() << endl;
  cout << "# of total words: " << instance.getTotalWords() << endl;

  cout << "now adding Co0o @1,k" << endl;
  cout << instance.incrWordCount("Co0o @1,k") << endl;
  cout << "now adding b1l-bul" << endl;
  cout << instance.incrWordCount("b1l-bul") << endl;
  cout << "now removing '': " << instance.decrWordCount("") << endl;
  
  cout << "# of 'cook's: " << instance.getWordCount("cook") << endl;
  cout << "# of 'B1l-BUL's: " << instance.getWordCount("B1l-BUL") << endl;
  cout << "# of ''s       : " << instance.getWordCount("") << endl;
  cout << "# of unique words: " << instance.getNumUniqueWords() << endl;
  cout << "# of total words: " << instance.getTotalWords() << endl;

  cout << "now removing [c>6^Oo233# k-" << endl;
  cout << instance.decrWordCount("[c>6^Oo233# k-") << endl;

  cout << "# of 'cook's: " << instance.getWordCount("cook") << endl;
  cout << "# of unique words: " << instance.getNumUniqueWords() << endl;
  cout << "# of total words: " << instance.getTotalWords() << endl;
  
  cout << "now adding  c0 oo&.k " << endl;
  cout << instance.incrWordCount(" c0 oo&.k ") << endl;
  cout << "now adding b3'3p b0'0p" << endl;
  cout << instance.incrWordCount("b3'3p b0'0p") << endl;
  cout << "now adding co'ok" << endl;
  cout << instance.incrWordCount("co'ok") << endl;
  cout << "now adding -c0oo~k'" << endl;
  cout << instance.incrWordCount("-c0oo~k'") << endl;

  cout << "# of 'C!;; o:,./O/~ k's: " << instance.getWordCount("C!;; o:,./O/~ k") << endl;
  cout << "# of unique words: " << instance.getNumUniqueWords() << endl;
  cout << "# of total words: " << instance.getTotalWords() << endl;

  cout << "is 4 a word char? " << instance.isWordChar('4') << endl;
  cout << "is Q a word char? " << instance.isWordChar('Q') << endl; 


  cout << "\nnow adding gainly: " << instance.incrWordCount("gainly");
  cout << "\nnow adding gainly: " << instance.incrWordCount("gainly");
  cout << "\nnow adding laying: " << instance.incrWordCount("laying");
  cout << "\nnow adding kbying: " << instance.incrWordCount("kbying") << endl;

  cout << "# of 'gainly's: " << instance.getWordCount("gainly") << endl;
  cout << "# of 'laying's: " << instance.getWordCount("laying") << endl;
  cout << "# of 'kbying's: " << instance.getWordCount("kbying") << endl;
  cout << "# of unique words: " << instance.getNumUniqueWords() << endl;
  cout << "# of total words: " << instance.getTotalWords() << endl;

  cout << "now removing kbying: " << instance.decrWordCount("kbying") << endl;
  cout << "now removing gainly: " << instance.decrWordCount("gainly") << endl;

  cout << "# of 'gainly's: " << instance.getWordCount("gainly") << endl;
  cout << "# of 'laying's: " << instance.getWordCount("laying") << endl;
  cout << "# of 'kbying's: " << instance.getWordCount("kbying") << endl;
  cout << "# of unique words: " << instance.getNumUniqueWords() << endl;
  cout << "# of total words: " << instance.getTotalWords() << endl;
*/

  cout << "\n\nDone testing class WordCount...\n\n" << endl;



  /*ASSERT_EQUALS(1234567,s1.getPerm());

  ASSERT_EQUALS("Smith",s1.getLastName());
  ASSERT_EQUALS("Malory Logan",s1.getFirstAndMiddleNames());
  ASSERT_EQUALS("Malory Logan Smith",s1.getFullName());
  ASSERT_EQUALS("[1234567,Smith,Malory Logan]",s1.toString());

  Student s2("7654321,Jones,Peter Mark");

  ASSERT_EQUALS(7654321,s2.getPerm());
  ASSERT_EQUALS("Jones",s2.getLastName());
  ASSERT_EQUALS("Peter Mark",s2.getFirstAndMiddleNames());*/
  
  return 0;
}
