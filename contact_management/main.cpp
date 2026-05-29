#include<iostream>
#include<fstream>
#include<string>
#include<limits>
#include<sstream>
using namespace std;
string toLowerStr(string s){
    for(char &c:s){
        c = tolower(c);
    }
    return s;
}
int main(){
int n;
 
//searching
string search;
string line;
bool found = false;

//write data
string name, number;

  
    do{
        cout<<endl<<"Choose option."<<endl;
        cout<<"1. Add Contact"<<endl;
        cout<<"2. Show All Contact"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Update"<<endl;
        cout<<"5. Delete"<<endl;
        cout<<"0. Exit."<<endl;
        cout<<"\n Select: ";


       
        cin>>n;
        //cin.ignore();
        if(cin.fail()){
            cout<<"Invalid input! Please enter only integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        
        else if(n==1){
            cout<<endl<<"------- Add New Contact -------"<<endl;
            while(true){
                string newName, newNumber;
                cout<<"Enter the name: ";
                getline(cin>>ws,newName);
                
                if(newName=="0"){
                    break;
                }
                
                ifstream checkNameFile("data.txt");
                string existLine;
                bool nameExists = false;

                while(getline(checkNameFile,existLine)){
                    size_t tabPos = existLine.find('\t');
                    if(tabPos !=string::npos){
                        string name = existLine.substr(0, tabPos);                    

                        if(name==newName){
                            nameExists = true;
                            break;
                        }
                    } 
                }
                checkNameFile.close();        
                
                
                if(nameExists){
                    cout<<"Name already exists!"<<endl<<endl;
                    break;
                }
                cout<<"Enter the number: ";
                getline(cin>>ws,newNumber);
                ifstream checkNumberFile("data.txt",ios::out|ios::app);
                bool numberExists = false;
                while(getline(checkNumberFile,existLine)){
                    size_t tabPos = existLine.find('\t');
                   if(tabPos !=string::npos){
                        string number = existLine.substr(tabPos + 1);
                        if(number ==newNumber){
                            numberExists = true;
                            break;
                        }
                   }
                }
                checkNumberFile.close();
                if(numberExists){
                    cout<<"Number already exists!"<<endl<<endl;
                    break;
                }
                ofstream wfile("data.txt",ios::out|ios::app);
                wfile<<newName<<"\t"<<newNumber<<endl;
                wfile.close();
                cout<<"Saved Successfully.."<<endl<<endl;              
            }
            cout<<endl<<"--------------------------------"<<endl; 
        }else if(n==2){
            string allContact;
            ifstream rfile("data.txt");
            string name,number;
            int i = 1;
            cout<<endl<<"------- Show All Contact -------"<<endl;
            while(getline(rfile,allContact)){
                cout<<i<<". "<<allContact<<endl;
                i++;
            }
            
            
            cout<<endl<<"--------------------------------"<<endl;
            rfile.close();
        }else if(n==3){
            
            //write code for edit data
            while(true){
                cout<<"Search name or number: ";
                getline(cin>>ws,search);
                search = toLowerStr(search);
                ifstream file("data.txt");
                cout<<endl<<"------- Searching Result -------"<<endl;
                
                while(getline(file,line)){
                    string lowerLine = toLowerStr(line);
                    
                    if(lowerLine.find(search)!=string::npos){
                        
                        cout<<line<<endl;
                        found=true;
                       
                    }
                     
                }
                file.close();
                if(!found){
                    cout<<"No contact found"<<endl;
                }
                cout<<endl<<"--------------------------------"<<endl;
                if(search=="0"){
                    break;
                }
            }
            
        }else if(n==4){
            cout<<endl<<"------- Update Status -------"<<endl;
            //write code for edit.
            string editLine, editSearch;
            int editChoice;
            while(true){
                cout<<"Enter name or number to edit: ";
                cin>>editSearch;
                cin.ignore();
                cout<<"\n1. Edit Name\n2. Edit Number\n3. Edit both\n Choose: ";
                cin>>editChoice;
                cin.ignore();
                if(name=="0" || number=="0" || editSearch=="0" ||editChoice==0){
                    break;
                }else{
                    

                    ifstream editFile("data.txt");
                    ofstream editTemp("temp.txt");
                    bool editFound = false;

                    while(editFile>>name>>number){
                        if(name == editSearch || number == editSearch){
                            editFound = true;
                            if(editChoice == 1){
                                cout<<"Enter new name: ";
                                getline(cin>>ws,name);
                            }else if(editChoice == 2){
                                cout<<"Enter new number: ";
                                getline(cin>>ws,number);
                            }else if(editChoice == 3){
                                cout<<"Enter new name: ";
                                getline(cin>>ws,name);

                                cout<<"Enter new number: ";
                                getline(cin>>ws,number);
                            }
                        }
                        editTemp<<name<<"\t"<<number<<endl;
                    }
                    editFile.close();
                    editTemp.close();
                    remove("data.txt");
                    rename("temp.txt","data.txt");
                    if(editFound){
                        cout<<"Updated successfully!"<<endl<<endl;
                    }else{
                        cout<<"No record found!";
                    }
                }
            }
            
            cout<<endl<<"--------------------------------"<<endl;
        }else if(n==5){

            cout<<endl<<"------- Deleted Status -------"<<endl;
             //write code for delete.
             string deleteLine, keyword;
             string checked_data;
             cout<<"\n1. All\n2. Individual\n Choose: ";
             getline(cin>>ws,checked_data);
             if(checked_data=="0"){
                break;
             }else if(checked_data=="1"){
                ofstream deleteFile("data.txt",ios::trunc);
                deleteFile.close();
                cout<<endl<<"------- Deleted Status -------"<<endl;
                cout<<"All contacts deleted successfully"<<endl;
             }else if(checked_data=="2"){
                cout<<"Enter name or number to delete: ";
                getline(cin>>ws,keyword);
                ifstream fin("data.txt");
                ofstream fout("temp.txt");
                bool found = false;
                while(getline(fin,deleteLine)){
                    if(deleteLine.find(keyword)==string::npos){
                        fout<<deleteLine<<endl;
                    }else{
                        found = true;
                    }
                }
                fin.close();
                fout.close();

                remove("data.txt");
                rename("temp.txt","data.txt");
                if(found){
                    cout<<endl<<"------- Deleted Status -------"<<endl;
                    cout<<"Deleted successfully!"<<endl<<endl;
                }else{
                    cout<<endl<<"------- Deleted Status -------"<<endl;
                    cout<<"No match found!"<<endl<<endl;
                }
             
             }
             cout<<endl<<"--------------------------------"<<endl; 
        }
        else if(n==0){
            cout<<"Exiting program...\n";  
            break;        
        }
        else{
            cout<<"Invalid Input! Please try again.\n";
        }
    }while(true);
   

  
    return 0;
}