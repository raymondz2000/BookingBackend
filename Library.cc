#include "Library.h"
#include <iostream>
#include <string>
const std::string red("\033[0;31m");
const std::string def("\033[0m");
using namespace std;

    int s_n;
    int r_n ;
    int re_n;
    int k;
  
Library::Library(){
    
   student_array = new Student*[100];
   reservation_array = new Reservation*[100];
   
   //set = 0 inside the constructor
    int s_n = 0;
    int r_n = 0;
    int re_n = 0;
    int k=0;
}   

Library::~Library(){
    
    for(int i=0; i<s_n; i++){
       delete student_array[i];
    }
    delete [] student_array;
      
    for(int i=0; i<re_n; i++){
       delete reservation_array[i];
    }
    //delete [] reservationrem_array;
    delete [] reservation_array;
    
    for(int i=0; i<r_n; i++){
        delete room_array[i];    
    }
   
    
     
}
//statically 
   
bool Library::addStudent(const string& name, const string& number){
    Student* add_s = new Student(name, number);
    
        if(s_n==0){
            student_array[s_n]=add_s;
            ++s_n;
            return true;
        }else{
            if(student_array[s_n-1]->lessThan(*add_s)==false){
                student_array[s_n]=student_array[s_n-1];
                student_array[s_n-1] = add_s;
                ++s_n;
                return true;
            }
            else{
                student_array[s_n]=add_s;
                ++s_n;
                return true;
                }
        }
}

bool Library::addRoom(string name, int capacity,int computers,bool whiteboard){
    /*
    	if (numPods >= MAX_PODS) return false;
	for (int i = numPods; i > 0; --i){
		if (p->lessThan(*podcasts[i-1])){
			podcasts[i] = podcasts[i-1];
		}else{
			podcasts[i] = p;
			++numPods;
			return true;
		}
	}
	podcasts[0] = p;
	++numPods;
	return true;
    */
   //this style of code have the same function below
    if(r_n<100){
        Room *add_r = new Room(name,capacity,computers,whiteboard);
        if(r_n==0){
            room_array[r_n]=add_r;
            ++r_n;
            return true;
        }else{
            if(room_array[r_n-1]->lessThan(*add_r)==false){
                room_array[r_n]=room_array[r_n-1];
                room_array[r_n-1] = add_r;
                ++r_n;
                return true;
            }
            else{
                room_array[r_n]=add_r;
                ++r_n;
                return true;
                }
        }
         
    }else{return false;}
}

bool Library::getStudent(const string& name, Student** student){
    
    for(int x = 0; x < s_n; x++){
        if((student_array[x]->getname() != name)&&(x==s_n)){
            return false;
        }
        else if (student_array[x]->getname() == name){
            *student = student_array[x];
            return true;
        
        }
    }
    return 0;
}
bool Library:: getRoom(const string& roomName, Room** room){
   
    for(int y = 0; y<r_n;y++){
        if ((room_array[y]->getroom_name() != roomName)&&(y==r_n-1)){
            return false;
        }
        else if(room_array[y]->getroom_name() == roomName){ 
            *room = room_array[y];
            return true;
        }
        
    }
    return 0;
}
bool Library::isFree(const string& room, Date& d){
   
   for(int y = 0; y < r_n;y++){
       //check room exist?
        if ((room_array[y]->getroom_name()!=room)&&(y==r_n-1)){
            //will not reach even you try to insert room not in the array
           return false;
        }
        //if room exist, check reservation
        else if(room_array[y]->getroom_name()==room){
            //check if people have reservation room
            if(re_n!=0){
                int found = 0;
                for(int x = 0; x<re_n;x++){
                    if(reservation_array[x]->getRoom()->getroom_name()==room){
                        found = x;
                        break;
                    }else if (x!=re_n){
                        continue;   
                    }
                }
                // if (found==0){
                //     return true;
                // }
                //else 
                //check over laps
                if(reservation_array[found]->overlaps(room,d)==false){
                        return true;
                }
            }
            else{
                return true;
            }
        }else{
            //KEEP GOING
            continue;
        }

    }
   return 0;
    
}
void Library::update(Date&d){
     
 cout<<"In update, as requested in a1-global.cc we need to remove all the date before: "<<endl;
 d.print();
 //we have done sorting so just delete wheatever is bigger than this one 
 cout<<"so, we need to remove: "<<endl;
    int num =0;
    for(int i = 0; i < re_n;i++){
        if (reservation_array[i]->getDate()->lessThan(d)){
            num = i;
            reservation_array[i]->getDate()->print();
            continue;
        }
        
    }
//num start from 0 and ends 2  but in this case we remove 3
     for(int i = num; i <=re_n; ++i){
        delete reservation_array[i-num];
        reservation_array[i-num] = reservation_array[num+1];
    }
    re_n-=num+1;
}
bool Library::makeReservation(const string& student, const string& room, Date& res_date){
     Student *found_student;
     Room *found_room;
     if(!getStudent(student,&found_student)||!getRoom(room,&found_room)){
         cout<<"****************************Make Reservation for "<<found_student->getname()<<" fault! ************************************"<<endl;
         return false;
     }
     else{
         if(!isFree(room,res_date)){
             cout<<"****************************Make Reservation for "<<found_student->getname()<<" fault! ************************************"<<endl;
             return false;
         }
         else{
            getStudent(student,&found_student);
            getRoom(room, &found_room);
            // reservation_array[re_n] = new Reservation(found_student, found_room,res_date);
            // re_n ++;
            //sort reservation_array;
            Reservation *add_res = new Reservation(found_student, found_room,res_date);
            if(re_n == 0){
                reservation_array[re_n] = add_res;
                ++re_n;
                return true;
            }
            else{
                if(reservation_array[re_n-1]->lessThan(*add_res)==false){
                    reservation_array[re_n] = reservation_array[re_n-1];
                    reservation_array[re_n-1] = add_res;
                    ++re_n;
                    cout<<found_student->getname()<<"  Make Reservation success!"<<endl;
                    return true;
                }else{
                    reservation_array[re_n] = add_res;
                    ++re_n;
                    cout<<found_student->getname()<<"  Make Reservation success!"<<endl;
                    return true;
                }
            }
            cout<<"****************************Make Reservation for "<<found_student->getname()<<" success!***********************************"<<endl;
         }
     }
}
void Library:: printReservations(){
    cout<<red<<"/------------------------   All student Have in library -------------------------------------------/"<<def<<endl<<endl;
    for(int i=0; i<s_n; i++){
        student_array[i]->print();
    }
    cout<<red<<"/-------------------------  All The room Have in library ------------------------------------------/"<<def<<endl<<endl;
    for(int i=0; i<r_n; i++){
        room_array[i]->print();
    }
    for(int i=0;i< re_n; i ++){
        cout<<red<<"/----------------------"<<" The reservation "<<i+1<< " of "<<re_n<<" is printing----------------------------------------/"<<def<<endl<<endl;
        reservation_array[i]->print();
        
    }
    cout<<red<<"/-------------------------  All Reservation sorted printed  ---------------------------------------/"<<def<<endl<<endl;
}
       