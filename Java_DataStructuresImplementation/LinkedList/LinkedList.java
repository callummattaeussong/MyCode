// Assignment #: Arizona State University CSE205 #10
//         Name: Callum Song
//    StudentID: 12127721843
//      Lecture: MWF 8.35am
//  Description: The Assignment 9 class displays a menu of choices to a user
//               and performs the chosen task. It will keep asking a user to
//               enter the next choice until the choice of 'Q' (Quit) is
//               entered.

import java.io.*;

public class LinkedList
{
   public static void main(String[] args)
   {
      char input1;
       String inputInfo = new String();
       int operation2;
       String line = new String();
       LinkedList list1 = new LinkedList();

       try
        {
         printMenu();

         InputStreamReader isr = new InputStreamReader (System.in);
         BufferedReader stdin = new BufferedReader (isr);

         do
          {
           System.out.print("What action would you like to perform?\n");
           line = stdin.readLine().trim();
           input1 = line.charAt(0);
           input1 = Character.toUpperCase(input1);

           if (line.length() == 1)
           {
             switch (input1)
             {
               case 'O':
                 System.out.print("The current size is " + list1.size() + "\n");
                 break;
               case 'A':
                 System.out.print("Please enter a string to add:\n");
                 String str1 = stdin.readLine().trim();
                 System.out.print("Please enter an index to add:\n");
                 inputInfo = stdin.readLine().trim();
                 int addIndex = Integer.parseInt(inputInfo);
                 list1.insertElement(addIndex, str1);
                 System.out.print(str1 + " is inserted at index " + addIndex + "\n");
                 break;
               case 'I':
                 System.out.print("Please enter a string to search:\n");
                 inputInfo = stdin.readLine().trim();
                 operation2=list1.searchElement(inputInfo);
                 if (operation2 > -1)
                   System.out.print(inputInfo + " found at index " + operation2 + "\n");
                 else
                   System.out.print(inputInfo + " not found\n");
                 break;
               case 'E':
                 System.out.print("Please enter an index to search:\n");
                 inputInfo = stdin.readLine().trim();
                 int searchIndex = Integer.parseInt(inputInfo);
                 System.out.print("string at index " + searchIndex + " is " + list1.getElement(searchIndex) + "\n");
                 break;
                case 'S':
                 System.out.print("Please enter a new string to set:\n");
                 String str2 = stdin.readLine().trim();
                 System.out.print("Please enter an index to set:\n");
                 inputInfo = stdin.readLine().trim();
                 int setIndex = Integer.parseInt(inputInfo);
                 list1.setElement(setIndex, str2);
                 System.out.print(str2 + " is set at index " + setIndex + "\n");
                 break;

               case 'R':
                 System.out.print("Please enter an index to remove:\n");
                 inputInfo = stdin.readLine().trim();
                 int removeIndex = Integer.parseInt(inputInfo);
                 list1.removeElement(removeIndex);
                 System.out.print("string at index " + removeIndex + " is removed\n");
                 break;
                case 'C':
                 System.out.print("Please enter a string to count:\n");
                 inputInfo = stdin.readLine().trim();
                 int counter1 =list1.countHowMany(inputInfo);
                 System.out.print("There are " + counter1 + " " + inputInfo + " found inside the linked list\n");
                 break;
                case 'D':
                 System.out.print("Please enter a string to remove:\n");
                 inputInfo = stdin.readLine().trim();
                 list1.removeDuplicate(inputInfo);
                 System.out.print(inputInfo + " is removed from the linked list\n");
                 break;
                case 'P':
                 System.out.print("Please enter a string to append at the end:\n");
                 String str3 = stdin.readLine().trim();
                 System.out.print("Please enter the number of times you want to append:\n");
                 inputInfo = stdin.readLine().trim();
                 int times = Integer.parseInt(inputInfo);
                 list1.appendAtEnd(str3, times);
                 System.out.print(str3 + " is appended " + times + " times at end of the linked list\n");
                 break;
               case 'T':
                 System.out.print("Which string do you want to append after:\n");
                 String str4 = stdin.readLine().trim();
                 System.out.print("Please enter the string you want to append:\n");
                 inputInfo = stdin.readLine().trim();
                 list1.appendAfter(str4, inputInfo);
                 System.out.print(inputInfo + " is appended after " + str4 + "\n");
                 break;
                case 'V':
                 System.out.print("Please enter the number of elements you want to reverse:\n");
                 inputInfo = stdin.readLine().trim();
                 int reverseNum = Integer.parseInt(inputInfo);
                 list1.reverseFirstFew(reverseNum);
                 System.out.print("The first " + reverseNum + " elements are reversed\n");
                 break;
               case 'L':
                 System.out.print(list1.toString());
                 break;
               case 'Q':
                 break;
               case '?':
                 printMenu();
                 break;
               default:
                 System.out.print("Unknown action\n");
                 break;
              }
           }
          else
           {
             System.out.print("Unknown action\n");
            }
          } while (input1 != 'Q' || line.length() != 1);
        }
       catch (IOException exception)
        {
          System.out.print("IO Exception\n");
        }
    }
    public static void printMenu()
     {
       System.out.print("Choice\t\tAction\n" +
                        "------\t\t------\n" +
                        "O\t\tList Current Size\n" +
                        "I\t\tSearch Element\n" +
                        "E\t\tGet Element by Index\n" +
                        "S\t\tSet Element by Index\n" +
                        "A\t\tInsert Element by Index\n" +
                        "R\t\tRemove Element by Index\n" +
                        "C\t\tCount How Many\n" +
                        "D\t\tRemove Duplicates\n" +
                        "P\t\tAppend at the End\n" +
                        "T\t\tAppend After\n" +
                        "V\t\tReverse First Few\n" +
                        "L\t\tList Linked List\n" +
                        "Q\t\tQuit\n" +
                        "?\t\tDisplay Help\n\n");

    } //end of printMenu()
}
