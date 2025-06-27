#include <stdio.h>
#include <stdlib.h>
/*
Length- cm,inches,feet
Temperature - C,F,K
Currency - rupees doller euro 
Mass - ouces,pounds,grams     
*/
int main() {
  char category;
  char convert;
  int tempChoice;
  int currencyChoice;
  int massChoice;
  int lengthChoice;
  
  //Input variables
  
  float userinputUSD; 
  float userinputEUR; 
  float userinputINR;  
  
  float userinputOunce;
  float userinputPound; 
  float userinputGram; 
  
  float userinputF; 
  float userinputC; 
  float userinputK;
  
  float userinputCM; 
  float userinputIN; 
  float userinputFT;
  
  float FtoC; 
  float CtoF; 
  float KtoF;
  float FtoK;
  float KtoC;
  float CtoK;
  
  //Output variables
  
  float USDtoINR; 
  float USDtoEUR; 
  float INRtoEUR; 
  float INRtoUSD; 
  float EURtoINR; 
  float EURtoUSD; 
  
  float OunceToPound; 
  float OunceToGram;
  float GramToOunce;
  float GramToPound;
  float PoundToGram;
  float PoundToOunce;
  
  float CMeterToInch; 
  float CMeterToFeet;
  float InchToCMeter;
  float InchToFeet;
  float FeetToCMeter;
  float FeetToInch;
  
  printf(" _____________________________\n");
  printf(" | Welcome to Unit Converter! |\n");
  printf(" _____________________________\n\n");
  
  do
  {
  printf("\nHere is a list of conversation to choose from: \n");
  printf("Length(L),Mass(M),Temperature(T),Currency(C) \n");
  printf("Please enter the letter you want to convert.\n\n");
  scanf(" %c",&category);
  category = toupper(category);
  switch(category)
  {
  
  case 'T':
      printf("\nHere is a list of conversations to choose from: \n\n");
      printf("Enter 1 for Fahrenheit to Celsius. \n");
      printf("Enter 2 for Celsius to Fahrenheit. \n");
      printf("Enter 3 for Kelvin to Fahrenheit. \n");
      printf("Enter 4 for Fahrenheit to Kelvin \n");
      printf("Enter 5 for Celsius to Kelvin. \n");
      printf("Enter 6 for Kelvin to Celsius. \n\n");
      scanf("%d",&tempChoice);
      if(tempChoice == 1){
        printf("Please enter the Fahrenheit degree: \n");
        scanf("%f",&userinputF);
        FtoC = ((userinputF-32)*(5.0/9.0));
        printf("Celsius: %.2f",FtoC);
      }
      else if(tempChoice == 2){
        printf("Please enter the Celsius degree: \n");
        scanf("%f",&userinputC);
        CtoF = ((9.0/5.0)*userinputC + 32);
        printf("Fahrenheit: %.2f",CtoF);
      }
      else if(tempChoice == 3){
        printf("Please enter the Kelvin degree: \n");
        scanf("%f",&userinputK);
        KtoF = ((9.0/5.0)*(userinputK-273.15) + 32);
        printf("Fahrenheit: %.2f",KtoF);
      }
      else if(tempChoice == 4){
        printf("Please enter the Fahrenheit degree: \n");
        scanf("%f",&userinputC);
        FtoK = ((userinputF-32)*(5.0/9.0))+273.15;
        printf("Kelvin: %.2f",FtoK);
      }
      else if(tempChoice == 5){
        printf("Please enter the Celsius degree: \n");
        scanf("%f",&userinputC);
        CtoK = (userinputC + 273.15);
        printf("Kelvin: %.2f",CtoK);
      }
      else if(tempChoice == 6){
        printf("Please enter the Kelvin degree: \n");
        scanf("%f",&userinputC);
        KtoC = (userinputK - 273.15);
        printf("Celsius: %.2f",KtoC);
      }
      else
        printf("Please enter the correct choice. \n");
      break;
  
   case 'C':
      printf("\nHere is a list of conversations to choose from: \n\n");
      printf("Enter 1 for USD to EUR. \n");
      printf("Enter 2 for USD to INR. \n");
      printf("Enter 3 for INR to USD. \n");        
      printf("Enter 4 for INR to EUR. \n");
      printf("Enter 5 for EUR to USD. \n");
      printf("Enter 6 for EUR to INR. \n\n");
      scanf("%d",&currencyChoice);
      if(currencyChoice == 1){
        printf("Please enter the USD amount: \n");
        scanf("%f",&userinputUSD);
        USDtoEUR = userinputUSD * 0.91;
        printf("EUR: %.2f",USDtoEUR); 
      }
      else if(currencyChoice == 2){
        printf("Please enter the USD amount: \n");
        scanf("%f",&userinputUSD);
        USDtoINR = userinputUSD * 82.26;
        printf("INR: %.2f",USDtoINR);
      }
      else if(currencyChoice == 3) {
        printf("Please enter the INR amount: \n");
        scanf("%f",&userinputINR);
        INRtoUSD = userinputINR * 0.012;
        printf("USD: %.2f",INRtoUSD);
      }
      else if(currencyChoice == 4) {
        printf("Please enter the INR amount: \n");
        scanf("%f",&userinputINR);
        INRtoEUR = userinputINR * 0.011;
        printf("EUR: %.2f",INRtoEUR);
      }
      else if(currencyChoice == 5) {
        printf("Please enter the EUR amount: \n");
        scanf("%f",&userinputEUR);
        EURtoUSD = userinputEUR * 1.10;
        printf("USD: %.2f",EURtoUSD);
      }
      else if(currencyChoice == 6) {
        printf("Please enter the EUR amount: \n");
        scanf("%f",&userinputEUR);
        EURtoINR = userinputEUR * 90.74;
        printf("USD: %.2f",EURtoINR);
      }
      else
        printf("Please enter correct choice. \n");
        break;
        
  case 'M':
      printf("\nHere is a list of conversations to choose from: \n\n");
      printf("Enter 1 for ounces to pounds. \n");
      printf("Enter 2 for ounces to grams. \n");
      printf("Enter 3 for gram to ounces. \n");
      printf("Enter 4 for gram to pounds. \n");
	  printf("Enter 5 for pounds to grams. \n");
	  printf("Enter 6 for pounds to ounces. \n");
      scanf("%d",&massChoice);
      if(massChoice == 1){
        printf("Please enter the ounce amount: \n");
        scanf("%f",&userinputOunce);
        OunceToPound = userinputOunce * 0.0625;
        printf("Pounds: %.2f",OunceToPound);
      }
      else if(massChoice == 2) {
        printf("Please enter the ounce amount: \n");
        scanf("%f",&userinputOunce);
        OunceToGram = userinputOunce * 28.3495;
        printf("Gram: %.2f",OunceToGram);
      }
      else if(massChoice == 3) {
        printf("Please enter the gram amount: \n");
        scanf("%f",&userinputGram);
        GramToOunce = userinputGram * 0.0352;
        printf("Ounce: %.2f",GramToOunce);
      }
      else if(massChoice == 4) {
        printf("Please enter the gram amount: \n");
        scanf("%f",&userinputGram);
        GramToPound = userinputGram * 0.0022;
        printf("Pounds: %.2f",GramToPound);
      }
      else if(massChoice == 5) {
        printf("Please enter the pound amount: \n");
        scanf("%f",&userinputPound);
        PoundToGram = userinputPound * 453.592;
        printf("Pounds: %.2f",PoundToGram);
      }
      else if(massChoice == 6) {
        printf("Please enter the pound amount: \n");
        scanf("%f",&userinputPound);
        PoundToOunce = userinputPound * 16;
        printf("Pounds: %.2f",PoundToOunce);
      }
      else 
        printf("Please enter the correct choice. \n");
      break;
	    
  case 'L':
      printf("\nHere is a list of conversations to choose from: \n\n");
      printf("Enter 1 for Centimeters to Inches. \n");
      printf("Enter 2 for Centimeters to Feet. \n");
      printf("Enter 3 for Inches to Centimeters. \n");
      printf("Enter 4 for Inches to Feet. \n");
      printf("Enter 5 for Feet to Centimeters. \n");
      printf("Enter 6 for Feet to Inches. \n");
      scanf("%d",&lengthChoice);
      if(lengthChoice == 1){
        printf("Please enter the centimeters: \n");
        scanf("%f",&userinputCM);
        CMeterToInch = userinputCM * 0.393;
        printf("Inches: %.2f",CMeterToInch);
      }
      else if(lengthChoice == 2) {
        printf("Please enter the centimeters: \n");
        scanf("%f",&userinputCM);
        CMeterToFeet = userinputCM * 0.0328;
        printf("Feet: %.2f",CMeterToFeet);
      }
      else if(lengthChoice == 3) {
        printf("Please enter the inches: \n");
        scanf("%f",&userinputIN);
        InchToCMeter = userinputIN * 2.54;
        printf("Centimeters: %.2f",InchToCMeter);
      }
      else if(lengthChoice == 4) {
        printf("Please enter the inches: \n");
        scanf("%f",&userinputIN);
        InchToFeet = userinputIN * 0.0833;
        printf("Feet: %.2f",InchToFeet);
      }
      else if(lengthChoice == 5) {
        printf("Please enter the feet: \n");
        scanf("%f",&userinputFT);
        FeetToCMeter = userinputFT * 30.48;
        printf("Feet: %.2f",FeetToCMeter);
      }
      else if(lengthChoice == 6) {
        printf("Please enter the feet: \n");
        scanf("%f",&userinputFT);
        FeetToInch = userinputFT * 12.0;
        printf("Feet: %.2f",FeetToInch);
      }
      else 
        printf("\nPlease enter the correct choice. \n");
      break;  
		      
   default: 
      printf("\nYou have not chosen the above mentioned method\n");
      exit(0);
   	   
  }
  printf("\n\nIf you like to use the converter again please enter Y \n");
  scanf(" %c",&convert);
  convert = toupper(convert);
  if(convert!='Y')
  printf("\nThank you for using the Unit Converter\n");
  printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");		
  }
  while(convert=='Y');
  return 0;
}
