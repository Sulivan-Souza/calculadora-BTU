#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
 
 
float calculate_power_required(float area, float region_factor, int doors, float quantity_equipment, float pot_equipment, 
float height, int num_lamps, float temp_desired, float temp_average, float slabs, int num_people, int num_windows_sun, int num_windows, 
float num_equipment, float activity_factor) {
 
  float power;
  power = area * height * (temp_desired - temp_average) ;
  power += num_people * 500; // 500 BTU's per person
  power += num_equipment + quantity_equipment * 500; // 500 BTU's per equipment
  power += pot_equipment * 0.1; // 10% of equipment power
  power *= activity_factor;// * 1.0 light, 1.2 moderate, 1.5 intense
  power += slabs; // with slabs + 160, without slabs + 315
  power += num_lamps * 50; // 50 BTU's per lamp
  power += num_windows_sun * 500; // 500 BTU's per window
  power += num_windows * 100; // 100 BTU's per window
  power += doors * 100; // 100 BTU's per num_doors
  power *= region_factor;// * 1.0 hot region, 1.1 mild region, 1.2 moderate region, 1.3 cold region, 1.4 very cold region
  return power;
  }
 
int main()
{
 
  int what_environment,doors,region, environment, option, num_people, type_activity,has_slabs,num_lamps, num_windows_sun, num_windows, windows;
  float length, region_factor, pot_equipment, width,num_equipment, quantity_equipment, height, area, slabs, temp_desired, temp_average, total_power, activity_factor;
  char buffer[256] ;
  char y = 'y';
  char n = 'n';
  char follow = y;
  int back = 1;
 
  while(follow != n)
  {
	system("cls");
 
	 while (back)  {
    
   
    printf("\n%35s Air Conditioning Power Calculator\n","");
    Sleep(2000);
    
    printf("\n%40s Software developed by: \n","");
    Sleep(2000);
    
	
	  printf("\n%39s SULIVAN; LUIZ; NATHACHA\n","");
    Sleep(1500);
  
    printf("\n%48s 2023 \n","");
    Sleep(2000);
    system("cls");
   
      printf("\n%30s Please provide the information requested below.:\n\n","");
      printf("\n%30s Press any key to continue\n","");
      
       Sleep(2000);
        printf("\n%30s Waiting for the user ........","");
      Sleep(2000);
      
      system("cls");
      
      if (_kbhit()){
        back = 0;
        getchar();
        }
     }
 
	system("cls"); 
 
	//type of environment/residential/commercial
	printf("The location is Residential or Commercial (1 for Residential, 2 for Commercial): ");
	fgets(buffer, sizeof(buffer), stdin);
 
	what_environment = strtol(buffer, NULL, 10);
 
	while(what_environment != 1 && what_environment != 2)
	{
  	printf("Invalid Location Type. Please enter again (1 for Residential, 2 for Commercial): ");
  	fgets(buffer, sizeof(buffer), stdin);
 
  	what_environment = strtol(buffer, NULL, 10);
	}
 
	//residential code/house/apartment
	if(what_environment == 1)
	{
  	system("cls");
 
  	printf(" House or Apartment? (1 for House, 2 for Apartment): ");
  	fgets(buffer, sizeof(buffer), stdin);
 
  	environment = strtol(buffer, NULL, 10);
          	
  	while(environment != 1 && environment != 2)
  	{
    	printf("Invalid choice. Please try again (1 for Home, 2 for Apartment): ");
    	fgets(buffer, sizeof(buffer), stdin);
 
    	environment = strtol(buffer, NULL, 10);
  	}
        	
  	//room/residential/house code
  	if(environment == 1)
  	{
    	system("cls");
 
    	printf("The House has suspended slabs (1 has slabs, 2 does not have slabs): ");
    	fgets(buffer, sizeof(buffer), stdin);
 
    	has_slabs = strtol(buffer, NULL, 10);
    	
    	while(has_slabs != 1 && has_slabs != 2 )
    	{
      	printf(" Invalid choice, Please try again (1 for Have, 2 for Don't have): ");
      	fgets(buffer, sizeof(buffer), stdin);
 	     has_slabs = strtol(buffer, NULL, 10);
    	}
 
    	if(has_slabs == 1)
    	{
      	slabs = 160;
    	}
    	if(has_slabs == 2)
    	{
      	slabs = 315;
    	}
  	}
  	
  	//room/residential/apartment code
  	if(environment == 2)
  	{
    	slabs = 160;
  	}         
	}
 
	//environment/commercial/suspended slabs type code
	if(what_environment == 2)
	{ 
  	system("cls");
  	printf("The Commercial has suspended slabs ( 1 has slabs, 2 does not have slabs): ");
  	fgets(buffer, sizeof(buffer), stdin);
  	
  	has_slabs = strtol(buffer, NULL, 10);
  	
  	while(has_slabs != 1 && has_slabs != 2 )
  	{
    	printf(" Invalid choice, Please try again (1 for Have, 2 for Don't have): ");
    	fgets(buffer, sizeof(buffer), stdin);
 
    	has_slabs = strtol(buffer, NULL, 10);
  	}
 
  	if(has_slabs == 1)
  	{
    	slabs = 160;
  	}
  	if(has_slabs == 2)
  	{
    	slabs = 315;
  	}
	}
	
	//UPS equipment/number of UPS equipment/power of UPS equipment
	system("cls");
 
	printf("Do you have equipment with uninterruptible power supply? (1 for Yes, 2 for No): ");
	fgets(buffer, sizeof(buffer), stdin);
 
	option = strtol(buffer, NULL, 10);
	
	while(option != 1 && option != 2)
	{
  	printf("Invalid option, Please try again (1 for Yes, 2 for No): ");
  	fgets(buffer, sizeof(buffer), stdin);
 
  	option = strtol(buffer, NULL, 10);
	}
 
	//code to have UPS equipment
	if(option == 1)
	{
  	system("cls");
  	printf("How many UPS equipment do you have: ");
  	fgets(buffer, sizeof(buffer), stdin);
 
  	quantity_equipment = strtol(buffer, NULL, 10);
 
  	while(quantity_equipment < 0)
  	{
    	printf("Invalid amount, Please try again: ");
    	fgets(buffer, sizeof(buffer), stdin);
 
    	quantity_equipment = strtol(buffer, NULL, 10);
  	}
 
  	//code for UPS equipment power
  	system("cls");
 
  	printf("What is the combined power of all UPS equipment: ");
  	fgets(buffer, sizeof(buffer), stdin);
 
  	pot_equipment = strtol(buffer, NULL, 10);
 
  	while(pot_equipment < 0)
  	{
    	printf("Invalid power, Please try again: ");
    	fgets(buffer, sizeof(buffer), stdin);
 
    	pot_equipment = strtol(buffer, NULL, 10);
  	}
	}
            	
	//code for not having UPS equipment
	if(option == 2)
	{
  	quantity_equipment = 0;
	}
 
	//environment area code
 
	//length
	system("cls");
 
	printf("Enter the length of the room in meters: ");
	fgets(buffer, sizeof(buffer), stdin);
 
	length = strtol(buffer, NULL, 10);
 
	while(length < 0)
	{
  	printf("Invalid information, Please try again: ");
  	fgets(buffer, sizeof(buffer), stdin);
 
  	length = strtol(buffer, NULL, 10);
	}
 
	//width
	system("cls");
 
	printf("Enter the width of the room in meters: ");
	fgets(buffer, sizeof(buffer), stdin);
 
	width = strtol(buffer, NULL, 10);
 
	while(width < 0)
	{
  	printf("Invalid information, Please try again");
  	fgets(buffer, sizeof(buffer), stdin);
 
  	width = strtol(buffer, NULL, 10);
	}
 
	//height
	system("cls");
 
	printf("Enter the height of the room in meters: ");
	fgets(buffer, sizeof(buffer), stdin);
 
	height = strtol(buffer, NULL, 10);
 
	while(height < 0)
	{
  	printf("Invalid information, Please try again");
  	fgets(buffer, sizeof(buffer), stdin);
 
  	height = strtol(buffer, NULL, 10);
	}
	
	area = length * width;
 
	//code for room temperature
	//desired temperature
	system("cls");
 
	printf("Enter the desired ambient temperature, in degrees Celsius: ");
	fgets(buffer, sizeof(buffer), stdin);
 
	temp_desired = strtol(buffer, NULL, 10);
 
	while(temp_desired < 0 || temp_desired > 45)
	{
  	printf("Invalid temperature, Please try again: ");
  	fgets(buffer, sizeof(buffer), stdin);
 
  	temp_desired = strtol(buffer, NULL, 10);
	}
	
	//room temperature
	system("cls");
 
	printf("Enter the average temperature of the environment, in degrees Celsius: ");
	fgets(buffer, sizeof(buffer), stdin);
 
	temp_average = strtol(buffer, NULL, 10);
 
	while(temp_average < 0 || temp_average > 45)
	{
  	printf("Invalid temperature, Please try again: ");
  	fgets(buffer, sizeof(buffer), stdin);
 
  	temp_average = strtol(buffer, NULL, 10);
	}
	
	// code for number of people
	system("cls");
 
	printf("Enter the average number of people circulating in the environment: ");
	fgets(buffer, sizeof(buffer), stdin);
	
	num_people = strtol(buffer, NULL, 10);
	
	while(num_people < 0)
	{
  	printf("Invalid amount, Please try again: ");
  	fgets(buffer, sizeof(buffer), stdin);
            	
  	num_people = strtol(buffer, NULL, 10);
	}
 
	// code for number of lamps
	system("cls");
 
	printf("Enter the number of bulbs: ");
	fgets(buffer, sizeof(buffer), stdin);
 
	num_lamps = strtol(buffer, NULL, 10);
 
	while(num_lamps < 0)
	{
    	printf("Invalid amount, Please try again: ");
    	fgets(buffer, sizeof(buffer), stdin);
 
    	num_lamps = strtol(buffer, NULL, 10);
	}
 
	// code for electronic equipment
	system("cls");
 
	printf("Enter the amount of electronic equipment('computers, TV, etc...'): ");
	fgets(buffer, sizeof(buffer), stdin);
 
	num_equipment = strtol(buffer, NULL, 10);
 
	while(num_equipment < 0)
	{
    	printf("Invalid amount, Please try again: ");
    	fgets(buffer, sizeof(buffer), stdin);
 
 	   num_equipment = strtol(buffer, NULL, 10);
	}
 
	//code for environment usage type
	system("cls");
 
	printf("Enter the type of activity in the environment (1 for Light, 2 for Moderate, 3 for Intense): ");
	fgets(buffer, sizeof(buffer), stdin);
 
	type_activity = strtol(buffer, NULL, 10);
 
	while(type_activity != 1 && type_activity != 2 && type_activity != 3)
	{
    	printf("Invalid activity type. Please enter again (1 for Light, 2 for Moderate, 3 for Intense): ");
    	fgets(buffer, sizeof(buffer), stdin);
 
    	type_activity = strtol(buffer, NULL, 10);
	}
 
	switch(type_activity)
	{
    	case 1:
    	activity_factor = 1.0;
    	break;
 
    	case 2:
    	activity_factor = 1.2;
    	break;
 
    	case 3:
    	activity_factor = 1.5;
    	break;
 
    	default:
    	printf("Invalid activity type. Using Moderate activity factor\n");
    	activity_factor = 1.2;
    	break;
	}
 
	// code for number of windows
	system("cls");
 
	printf("The Environment has windows: ( 1 - Yes 2 - No): ");
	fgets(buffer, sizeof(buffer), stdin);
 
	windows = strtol(buffer, NULL, 10);
 
	while(windows != 1 && windows != 2)
	{
    	printf("Invalid option, Please try again: ");
    	fgets(buffer, sizeof(buffer), stdin);
 
    	windows = strtol(buffer, NULL, 10);
	}
	if(windows == 1)
	{
    	system("cls");
    	
    	printf("Enter the number of windows: ");
    	fgets(buffer, sizeof(buffer), stdin);
 
    	num_windows = strtol(buffer, NULL, 10);
 
    	while(num_windows < 0)
    	{
        	printf("Invalid amount, Please try again: ");
        	fgets(buffer, sizeof(buffer), stdin);
 
        	num_windows = strtol(buffer, NULL, 10);
    	}
 
    	system("cls");
 
    	printf(" How many windows have direct sunlight: ");
    	fgets(buffer, sizeof(buffer), stdin);
 
    	num_windows_sun = strtol(buffer, NULL, 10);
 
        while(num_windows_sun < 0 || num_windows_sun > num_windows)
    	{
        	printf("Invalid amount, Please try again: ");
        	fgets(buffer, sizeof(buffer), stdin);
 
        	num_windows_sun = strtol(buffer, NULL, 10);
    	}
	}
	else
	{
	num_windows = 0;
	}
 
	// code for number of num_doors
	system("cls");
 
	printf("How many doors does the environment have:");
	fgets(buffer, sizeof(buffer), stdin);
 
	doors = strtol(buffer, NULL, 10);
	
	while(doors <= 0 )
	{
    	printf("Invalid option, Please try again: ");
    	fgets(buffer, sizeof(buffer), stdin);
 
    	doors = strtol(buffer, NULL, 10);
	}
 
	//code for region
	system("cls");
 
	printf("Enter the region of the country (1 for North, 2 for Northeast, 3 for Midwest, 4 for Southeast, 5 for South): ");
	fgets(buffer, sizeof(buffer), stdin);
 
	region = strtol(buffer, NULL, 10);
 
	while(region != 1 && region != 2 && region != 3 && region != 4 && region != 5)
	{
    	printf("Invalid region, Please try again: ");
    	fgets(buffer, sizeof(buffer), stdin);
 
    	region = strtol(buffer, NULL, 10);
	}
 
	switch (region)
	{
  	  case 1:
    	region_factor = 1.0;
    	break;
 
    	case 2:
    	region_factor = 1.1;
    	break;
 
    	case 3:
    	region_factor = 1.2;
    	break;
 
    	case 4:
    	region_factor = 1.3;
    	break;
            	
    	case 5:
    	region_factor = 1.4;
    	break;
            	
    	default:
    	printf("Invalid region. Using Southeast region factor\n");
    	region_factor = 1.3;
    	break;
	}
 
      	
	// power calculation
	total_power = calculate_power_required
	(area, doors, region_factor, num_lamps, height, temp_average, temp_desired, num_people, num_equipment, activity_factor,
	pot_equipment,quantity_equipment,slabs,num_windows_sun,num_windows);
 
	system("cls");
	printf(" \n You will need a device like: ");
	if(total_power < 7000 )
	{
    	printf("7 MIL" );
	}
 
	if(total_power > 7000 )
	{
    	if(total_power <= 9000 )
    	{
        	printf("9 MIL" );
    	}
	}
 
	if(total_power > 9000 )
	{
    	if(total_power <= 12000)
    	{
        	printf("12 MIL");
    	}
	}
 
	if(total_power > 12000)
	{
    	if(total_power <= 17000)
    	{
        	printf("17 MIL");
    	}
	}
 
	if(total_power > 17000)
	{
    	if(total_power <= 18000)
    	{
        	printf("18 MIL");
    	}
	}
 
	if(total_power > 18000)
	{
    	if(total_power <= 22000)
    	{
        	printf("22 MIL");
    	}
	}
 
	if(total_power > 22000)
	{
    	if(total_power <= 24000)
    	{
        	printf("24 MIL");
    	}
	}
 
	if(total_power > 24000)
	{
    	if(total_power <= 30000)
    	{
        	printf("30 MIL");
    	}
	}
 
	if(total_power > 30000)
	{
    	if(total_power <= 48000)
    	{
        	printf("32 MIL");
    	}
	}
 
	if(total_power > 48000)
	{
    	if(total_power <= 50000)
    	{
        	printf("50 MIL");
    	}
	}
 
	if(total_power > 50000)
	{
    	if(total_power <= 60000)
	    {
        	printf("60 MIL");
    	}
	}
 
	if(total_power > 60000)
	{
    	if(total_power <= 70000)
    	{
        	printf("70 MIL");
    	}
	}
 
	if(total_power > 70000)
	{
    	if(total_power <= 80000)
    	{
        	printf("80 MIL");
    	}
	}
 
	if(total_power > 80000)
	{
    	if(total_power <= 90000)
    	{
        	printf("90 MIL");
    	}
	}
 
	if(total_power > 90000)
	{
    	if(total_power <= 100000)
    	{
        	printf("100 MIL");
    	}
	}
 
	if(total_power > 100000)
	{
   	{
        	printf("more than 100 THOUSAND");
    	}
	}
    	
	printf(" BTUs/h\n");
      	
	// Convert BTU/hr to watts
	float kilowatts = total_power * 0.00029307107;
	printf("Total power of the equipment in %.2f Kw/h : \n\n", kilowatts);
 
	printf("press enter to continue\n");
	getchar();
 
	system("cls"); 
 
	printf("\nDo you want to perform another calculation? (y/n):");
	scanf("%c", &follow);
 
	while (follow != 'y' && follow != 'n')
	{
    	printf("Invalid answer. Do you want to calculate again? (y/n) ");
    	scanf(" %c", &follow);
	}
  }//while return
 
  return 0;
}/*main*/


