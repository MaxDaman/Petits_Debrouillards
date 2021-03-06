/*	MyMagicStick v_1.0
	Exemple Arduino -> Structure Conditionnelle
	@author Daman Maximilien
*/

//Variables generale
	int LumPin = A0;
	int LumValue = 0;
//Variables de temporisation:
	long			Interval[2] = {1500, 500};
	unsigned long	Previous[2] = {0, 0};
	unsigned long	Current[2];

void setup()
{
	//Initialisation de la communication:
	Serial.begin(9600);
	//Selection du sens de communcation capteur:
	pinMode(LumPin, INPUT);
}

void loop()
{
//Temporisation:
	for(uint8_t i = 0; i < 2; i++)
	{
		Current[i] = millis();
	}
	if(Current[0] - Previous[0] > Interval[0])
	{
	//Mise a jour Temporisation:
		Previous[0] = Current[0];
	//Mesure
		LumValue = analogRead(LumPin);
		LumValue = map(LumValue, 0, 1023, 0, 100);
	//Ecriture:
		PersonnalMessage();
	}
	else if(Current[1] - Previous[1] > Interval[1])
	{
	//Mise a jour Temporisation:
		Previous[1] = Current[1];
	//Ecriture:
		Serial.print(".");
	}
}

void PersonnalMessage()
{
//Ecriture donnée générale:
	Serial.print("\nLuminosity is @ ");
	Serial.print(LumValue);
	Serial.print("%\n\tSaison : ");
//Variable de nivellement:
	int Level = int(map(LumValue, 0, 100, 0, 3));
//Traitement du nivellement:
	switch(Level)
	{
		case 0:
			Serial.println("Hiver");
			break;
		case 1:
			Serial.println("Automne");
			break;
		case 2:
			Serial.println("Printemps");
			break;
		case 3:
			Serial.println("Ete");
			break;
		default:
			break;
	}
	return;
}
