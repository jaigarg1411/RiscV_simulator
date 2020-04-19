#ifndef CONTROLHAZARDS_H
#define CONTROLHAZARDS_H

// convert binary string to decimal
bool isTaken = false , predictedInstruction = false , CorrectPrediction = false ,branchStall = false;
int BranchOutcome , oldPc ;
pair<int ,int > table;
int bintodec(string s)
{
	int val=0,index=0,i;
	for(i=s.length()-1;i>=0;i--)
	{
		if(s[i] == '1')
			val += pow(2,index);
		index++;
	}
	return val;
}


// 2s compliment for negative immidiates
string findTwoscomplement(string str) 
{ 
    int n = str.length(); 
    int i; 
    for (i = n-1 ; i >= 0 ; i--) 
        if (str[i] == '1') 
            break; 
    if (i == -1) 
        return '1' + str; 
    for (int k = i-1 ; k >= 0; k--) 
    { 
        if (str[k] == '1') 
            str[k] = '0'; 
        else
            str[k] = '1'; 
    } 
    return str;; 
} 

int bintodec_negative(string s)
{
	string str = findTwoscomplement(s);
	int res = bintodec(str);
	res = 0-res;
	return res;
}


string hextobin(string inst)
{
     stringstream ss;
     ss << hex << inst;
     unsigned n;
     ss >> n;
     bitset<32> b(n);
     string s = b.to_string();
     return s;
}



bool checkPrediction(int funct3 , int RA , int RB ,bool isTaken)
{
    
    if(funct3 == 0)
    {
        cout<<"beq"<<endl;
        if(RA == RB)
        {
            if(isTaken == true)
                return true;
            else return false;
        }
        else
        {
            if(isTaken == true)
                return false;
            else return true;
        }
        
    }
    if(funct3 == 1)
    {
        cout<<"bne"<<endl;
        if(RA != RB)
        {
            if(isTaken == true)
                return true;
            else return false;
        }
        else
        {
            if(isTaken == true)
                return false;
            else return true;
        }
        
    }
    if(funct3 == 4)
    {
        cout<<"blt"<<endl;
        if(RA < RB)
        {
            if(isTaken == true)
                return true;
            else return false;
        }
        else
        {
            if(isTaken == true)
                return false;
            else return true;
        }
        
    }
    if(funct3 == 5)
    {
        cout<<"bge"<<endl;
        if(RA >= RB)
        {
            if(isTaken == true)
                return true;
            else return false;
        }
        else
        {
            if(isTaken == true)
                return false;
            else return true;
        }
        
    }
}

int getPcCj(string IR , bool &isTaken ,int pc)
{
    string op_str,rd_str,funct3_str,rs1_str,rs2_str,funct7_str,ImmiSubstring;
    funct3_str = IR.substr(17,3);
		
	string temp,temp1,temp2,temp3;
	temp = IR.substr(0,1);
	temp1 = IR.substr(24,1);
	temp2 = IR.substr(1,6);
	temp3 = IR.substr(20,4);
	ImmiSubstring = temp + temp1 + temp2 + temp3; // rearranging immidiates bits
	ImmiSubstring.append("0");
		
	int immidiate;
	if(ImmiSubstring[0]=='0')
		immidiate = bintodec(ImmiSubstring);
	else
		immidiate = bintodec_negative(ImmiSubstring);
    if(immidiate<0)
    {
        isTaken = true;
        return pc+immidiate;
    }
    else
    {
        isTaken = false;
        return pc+4;
    }
}
int calcBranch(int funct3, int immediate, int currentPc , int RA ,int RB)
{
    cout<<"current pc "<<currentPc<<endl;
    cout<<"RA "<<RA<<" RB "<<RB<<endl;
    if(funct3 == 0)
    {
        if(RA == RB)
        {
            return currentPc+immediate;
        }
        else
        {
            return currentPc+4;
        }
        
    }
    if(funct3 == 1)
    {
        if(RA != RB)
        {
            return currentPc+immediate;
        }
        else
        {
            return currentPc+4;
        }
        
    }
    if(funct3 == 4)
    {
        if(RA < RB)
        {
            return currentPc+immediate;
        }
        else
        {
            return currentPc+4;
        }
        
    }
    if(funct3 == 5)
    {
        if(RA >= RB)
        {
            return currentPc+immediate;
        }
        else
        {
            return currentPc+4;
        }
        
    }

}


#endif