#include <iostream>
#include <vector>

using namespace std;


class Person{
  protected:
    string firstName;
    string lastName;
    int id;
  public:
    Person(string firstName, string lastName, int identification){
      this->firstName = firstName;
      this->lastName = lastName;
      this->id = identification;
    }
    void printPerson(){
      cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
    }
  
};


class Student :  public Person{
  private:
    vector<int> testScores;
    int numScores;
  public:
        /*  
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        Student(string firstName, string lastName, int id, vector<int> scores): Person(firstName, lastName, id)
        {
          this->testScores = scores;
          this->numScores = this->testScores.size();
        }

        /*  
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate()
        {
          char g;
          int scoresSum;
          double scoresAvg;

          for(unsigned int i=0; i<this->numScores; i++)
          {
            scoresSum += this->testScores[i];
          }

          scoresAvg = scoresSum/this->numScores;

          if     (scoresAvg>=90 && scoresAvg<=100)  g = 'O';
          else if(scoresAvg>=80 && scoresAvg<=90)   g = 'E';
          else if(scoresAvg>=70 && scoresAvg<=80)   g = 'A';
          else if(scoresAvg>=55 && scoresAvg<=75)   g = 'P';
          else if(scoresAvg>=40 && scoresAvg<=55)   g = 'D';
          else if(scoresAvg<40)                     g = 'T';

          return g;
        }
};


int main() {
  string firstName;
    string lastName;
  int id;
    int numScores;
  cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;
    for(int i = 0; i < numScores; i++){
      int tmpScore;
      cin >> tmpScore;
    scores.push_back(tmpScore);
  }
  Student* s = new Student(firstName, lastName, id, scores);
  s->printPerson();
  cout << "Grade: " << s->calculate() << "\n";
  return 0;
}