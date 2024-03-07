/*
DATA STRUCTURE AND ALGORITHM PROJECT
GROUP 4 MEMBERS
1, ABSIRA BELAY RU0457/13
2, AISHA AMRU RU0195/13
3, CHALA GOLICHA RU3367/13
4, DIRIBA BEDASA RU2433/13
5, HABTAMU GELANA RU 3486/13
6, KALAB GIRMA RU2896/13
7, MEKIYA KEMAL RU2169/13
*/
#include <iostream>
#include <string.h>
using namespace std;
#define limit 50
int globalvariable = 0;
class booktype
{
private:
  char nameofbook[limit];
  char nameofauthor[limit];
  char YearofBookPublished[limit];
  float priceofbook;

public:
  char ISBN[50];
  void setbookinformation();
  char getnameofbook();
  booktype()
  {
    strcpy(nameofbook, " ");
    strcpy(nameofauthor, " ");
    strcpy(YearofBookPublished, " ");
  }
  void PrintBookInformation();
  void BubbleSortingBYISBN(booktype book_data[]);
  void InsertionSortByNameOfBook(booktype book_data[]);
  void SelectionSortByYearofBookPublished(booktype book_data[]);
  int BinarySearchByISBN(booktype book_data[], char key[limit]);
  int LinearSearchByAuthor(booktype book_data[], char item[limit]);
  void DeleteByISBN(booktype book_data[], char item[]);
};
void booktype::setbookinformation()
{
  cout << "\n Enter book name: ";
  cin >> nameofbook;
  cout << "\n Enter author's name :";
  cin >> nameofauthor;
  cout << "\n Enter book year :";
  cin >> YearofBookPublished;
  cout << "\n Enter ISBN :";
  cin >> ISBN;
  cout << "\n Enter price of the book :";
  cin >> priceofbook;
}
void booktype::PrintBookInformation()
{
    cout<< "\t" << nameofbook << "\t"
         << "\t" << nameofauthor << "\t"
         << "\t\t" << YearofBookPublished <<"\t\t\t"<< ISBN << "\t\t" << priceofbook <<endl;

}
void booktype::BubbleSortingBYISBN(booktype book_data[])
{

  booktype temp;
  for (int i = 0; i < globalvariable-1; i++)
  {
    for (int j = 0; j < globalvariable-i-1; j++)
    {
      if (strcmp(book_data[j+1].ISBN, book_data[j].ISBN) < 0)
      {
        temp = book_data[j];
        book_data[j] = book_data[j+1];
        book_data[j+1] = temp;
      }
    }
  }
}
void booktype::InsertionSortByNameOfBook(booktype book_data[])
{
  int index, index2;
  booktype temp;
  for (index = 1; index < globalvariable; index++)
  {
    temp = book_data[index];
    for (index2 = index; index2 > 0 && strcmp(book_data[index2 - 1].nameofbook , temp.nameofbook)>0; index2--)
    {
      book_data[index2] = book_data[index2 - 1];
    }
    book_data[index2] = temp;
  }
}
void booktype::SelectionSortByYearofBookPublished(booktype book_data[])
{
  booktype temp, smalleststring;
  int iter, index1, smallest;
  for (iter = 0; iter < globalvariable - 1; iter++)
  {
    smallest = iter;
    smalleststring = book_data[iter];
    for (index1 = iter + 1; index1 < globalvariable; index1++)
    {
      if (strcmp(book_data[index1].YearofBookPublished, book_data[smallest].YearofBookPublished) < 0)
      {
        smallest = index1;
        smalleststring = book_data[index1];
      }
    }
    if (smallest != iter)
    {
      temp = book_data[smallest];
      book_data[smallest] = book_data[iter];
      book_data[iter] = temp;
    }
  }
}
int booktype::LinearSearchByAuthor(booktype book_data[], char item[limit])
{
  int iter = 0, pos = -1;

  for (iter; pos == -1 && iter < globalvariable; iter++)
  {
    if (strcmp(item, book_data[iter].ISBN) == 0)
    {
      pos = iter;
    }
  }
  if (pos >= 0)
  {


    return pos;
  }
  else
    return -1;
}
int booktype::BinarySearchByISBN(booktype data[], char key[limit])
{ booktype s1;
s1.BubbleSortingBYISBN(data);
  int start, mid, end, iter = 0;
  start = 0;
  end = globalvariable - 1;
  int flag = -1;
  for (iter; iter < globalvariable && start <= end && flag == -1; iter++)
  {
    mid = (start + end) / 2;
    if (strcmp(key,data[mid].ISBN) == 0)
    {
      flag = mid;
    }
    else if (strcmp(key, data[mid].ISBN) < 0)
    {
      end = mid - 1;
    }
    else
      start = mid + 1;
  }
  if (flag == 1)
  {
   return mid;
  }
  else
  { return -1;

  }
}
void booktype::DeleteByISBN(booktype book_data[], char item[])
{
  int iter, found = -1;
  for (iter = 0; iter < globalvariable && found == -1; iter++)
  {
    if (strcmp(item, book_data[iter].ISBN)==0)
    {
      for (iter = iter; iter < globalvariable - 1; iter++)
      {
        book_data[iter] = book_data[iter + 1];
        found++;
        globalvariable--;
      }
    }
  }
  if (found != -1)
  {
    cout << "u deleted book with ISBN "<<item<<" from book_data: ";
  }

  else
    cout << "invalid input";
}
int main()
{

  int locater,pos = 0;
  char item[limit];
  char op;
  booktype s1,d1 ,data[1000];
Menu:
  cout << "\n press 1 to set data ";
  cout << "\n press 2 to print data ";
  cout << "\n press 3 for bubble sorting by ISBN ";
  cout << "\n press 4 for insertion sorting name of book ";
  cout << "\n press 5 for selection sorting year of book ";
  cout << "\n press 6 for linear searching ";
  cout << "\n press 7 for binary searching ";
  cout << "\n press 8 for deletion ";
  cout << "\n press 0 to exit  ";
  cout << "\n select task ";
  cin >> op;
  switch (op)
  {
  case '1':
    data[globalvariable].setbookinformation();
    globalvariable++;
    break;
    label:
  case '2':

      cout << "\t"
       << "No"
       << "\t"
       << "nameofbook"
       << "\t"
       << "nameofauthor"
       << "\t"
       << "YearofBookPublished"
       << "\t\t"
       << "ISBN"
       << "\t\t"
       << "priceofbook" << endl;
  cout << "\n -------------------------------------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i < globalvariable; i++)
    { cout<<"\t"<<i+1<<".";
      data[i].PrintBookInformation();
    }
    break;
  case '3':
    s1.BubbleSortingBYISBN(data);
    goto label;
    break;
  case '4':
    s1.InsertionSortByNameOfBook(data);
    goto label;
    break;
  case '5':
    s1.SelectionSortByYearofBookPublished(data);
    goto label;
    break;
  case '6':
    cout << "enter book ISBN u want to search:";
    cin >> item;
   locater=s1.LinearSearchByAuthor(data, item);
   if(locater>=0){ data[locater].PrintBookInformation();
} else {cout<<" no element u searched for:";}

        break;

  case '7':
    cout << "enter ISBN of book u want to search by binary searching:";
    cin >> item;

    locater=d1.BinarySearchByISBN(data, item);
    if(locater>=0){

    data[locater].PrintBookInformation();}
    else { cout<<" \n No found book information with this information";}
    break;
  case '8':
    cout << "enter ISBN of book u want delete :";
    cin >> item;
    s1.DeleteByISBN(data, item);
    goto label;
    break;
  case '0':
    exit(0);
    break;
  default:
    cout << " selector is incorrect";
  }
  goto Menu;
  return 0;
}

