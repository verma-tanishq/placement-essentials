int isPalindrome(string str){
  int i=0;
  int j=str.size()-1;
  while(i<j){
    if(str[i]==str[j]){
      i++;
      j--;
    }
    else{
      return 0;
    }
  }
  return 1;
}
