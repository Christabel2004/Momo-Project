#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> Name;
vector<string> Phone;
vector<string> Pin;

void authentication();
void reset_pin();
void check_balance();
void send_money();

string name;
string phone;
string pin;
	float amount = 1000.00;
	float balance;
int main(int argc, char** argv) {
    int sel = 0;
    
    while (true) {
        cout << "\n\nMobile Money Service\n\n";
        cout << "Hello, " << name << endl;
        cout << "\n[1] Authentication\n";
        cout << "[2] Reset Pin/ Change Pin\n";
        cout << "[3] Check Balance\n";
        cout << "[4] Send Money\n";
        cout<<" [0] Exit\n";
        cout << "\nEnter option:";
        cin >> sel;
        
        switch (sel) {
            case 1:
                authentication();
                break;
            case 2:
                reset_pin();
                break;
            case 3:
                check_balance();
                break;
            case 4:
                send_money();
                break;
            default:
                cout << "Invalid option";
        }
        
        if (sel == 0) {
            break;
        }
    }
    
    return 0;
}

void authentication() {
    cout << "Register your account\n";
    cout << "\n\nEnter your name: ";
    cin >> name;
    cout << "Enter your phone number: ";
    cin >> phone;
    
    // prompt the user to enter a 4-digit PIN
    while (true) {
        cout << "Enter your pin (exactly 4 digits): ";
        cin >> pin;
        
        if (pin.length() == 4) {
            break;
        } else {
            cout << "\nInvalid PIN. Please enter exactly 4 digits.\n";
        }
    }
    
    Name.push_back(name);
    Phone.push_back(phone);
    Pin.push_back(pin);
    cout << "\nRegistered successfully!\n";
}

void reset_pin() {
    string old_pin;
    string new_pin;
    string confirm_pin;
    cout << "\nReset pin or change pin\n" << endl;

    while (true) {
        cout << "Enter current pin: ";
        cin >> old_pin;
        cout << "Enter new pin: ";
        cin >> new_pin;
        cout << "Confirm new pin: ";
        cin >> confirm_pin;

        if (old_pin != pin) {
            cout << "\nInvalid PIN. Please enter your current pin.\n";
        } else if (new_pin.length() != 4) {
            cout << "\nInvalid PIN. Please enter exactly 4 digits.";
        } else if (new_pin != confirm_pin) {
            cout << "\nNew PIN and confirmation do not match. Please try again.\n";
        } else {
            // find the index of the current user in the vectors
            int index = -1;
            for (int i = 0; i < Name.size(); i++) {
                if (Name[i] == name && Phone[i] == phone && Pin[i] == old_pin) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                cout << "\nError: User not found.\n";
            } else {
                // replace the old PIN with the new PIN
                Pin.at(index) = new_pin;
                cout << "\nYour pincode is changed successfully!\n";
                break;
            }
        }
    }
}

void check_balance() {
    string pincode;
    int attempts = 0;

    for (int i = 0; i < 3; i++) {
        cout << "Enter your pincode: ";
        cin >> pincode;

        if (pincode != pin) {
            cout << "Your current balance is GHS" << amount << endl;
            break;
        }
		 else {
            attempts++;
            cout << "\nInvalid pincode" << endl;
        }
    }

    if (attempts == 3) {
        cout << "\nToo many attempts. Returning to main menu.\n";
    }
}

void send_money(){
	
	float amnt = 0.00;
	int re_num;
	int c_num;
	string pin_code;
	
	cout<<"\nSending money to another momo user\n"<<endl;
	
	while(true){
		cout<<"Enter recipient's number: "; 
	    cin>>re_num;
	    cout<<"Confirm recipient's number: ";
	    cin>>c_num;
	    
	    if(re_num!=c_num){
	    	cout<<"\nRecipient number does not match. Please enter recipient number again.\n";
		}
		else{
			cout<<"\nEnter amount:";
			cin>>amnt;
			break;
		}
	}
	
	int tries = 0;
	
	while (true) {
		cout << "\nEnter your pin: "; 
		cin >> pin_code;
		
		if (pin_code != pin) {
            if(amnt>amount){
            	cout<<"Insufficient balance to make this transaction"<<endl;
            	break;
			}
			else{
				balance = amount-amnt;
				amount = balance;
				cout << "\nTransaction successful. " << "GHS" << amnt << " has been sent to " << re_num << "." << endl;
				cout << "Your current balance is GHS" << amount << endl;
				break;
			}
        } else {
            tries++;
            cout << "\nInvalid pincode" << endl;
        }
		
		if (tries == 3) {
			cout << "\nToo many attempts. Returning to main menu.\n";
			break;
		}
	}
}

