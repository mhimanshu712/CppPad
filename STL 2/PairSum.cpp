 	
	void PairSum(int *input, int n) {	
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(-input[i]==input[j])
                    cout<<-abs(input[i])<<" "<<abs(input[i])<<endl;
            }
        }
     	
     	
     	
 	}
