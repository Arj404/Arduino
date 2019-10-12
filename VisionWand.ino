byte refreshrrate = 1000000;
String str = "9:30 AM";
const boolean LA[] = {
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
};

const boolean LM[] = {
  1, 0, 0, 0, 0, 0, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 1, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
};

const boolean LP[] = {
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0,
};

const boolean BR[] = {
  0, 0,
  0, 0,
  0, 0,
  0, 0,
  0, 0,
  0, 0,
  0, 0,
  0, 0,
  0, 0,
  0, 0,
};

const boolean DOT[] = {
  0, 0,
  1, 1,
  1, 1,
  1, 1,
  0, 0,
  0, 0,
  1, 1,
  1, 1,
  1, 1,
  0, 0,
};

const boolean N1[] = {
  0, 0, 1, 1, 1,
  0, 1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 1, 1, 1, 1,
  1, 0, 1, 1, 1,
  0, 0, 1, 1, 1,
  0, 0, 1, 1, 1,
  0, 0, 1, 1, 1,
  0, 0, 1, 1, 1,
  0, 0, 1, 1, 1,
};

const boolean N2[] = {
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
};

const boolean N3[] = {
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
};

const boolean N4[] = {
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
};

const boolean N5[] = {
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
};

const boolean N6[] = {
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
};

const boolean N7[] = {
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
};

const boolean N8[] = {
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
};

const boolean N9[] = {
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
};

const boolean N0[] = {
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1,
};

const boolean LOAD[] = {
  1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
};

void sendtowand(const boolean letter[], byte l) {
  for (byte t = 0; t < l; t++) {
    for (int pin = 10; pin >= 1; pin--) {
      boolean ptr = letter[(10-pin)*l+t]);
      Serial.print(ptr);
      Serial.print("   ...   ");
      Serial.println((10 - pin)*l + t);
      if (ptr==1) {
        digitalWrite(pin+2, HIGH);
      } else {
        digitalWrite(pin+2, LOW);
      }
    }
  }
}



void disp(char ch) {
  switch (ch) {
    case 'A': {
        sendtowand(A, 6);
        sendtowand(BR, 2);
        break;
      }
    case 'M': {
        sendtowand(M, 7);
        sendtowand(BR, 2);
        break;
      }
    case 'P': {
        sendtowand(P, 6);
        sendtowand(BR, 2);
        break;
      }
    case '0': {
        sendtowand(N0, 6);
        sendtowand(BR, 2);
        break;
      }
    case '1': {
        sendtowand(N1, 5);
        sendtowand(BR, 2);
        break;
      }
    case '2': {
        sendtowand(N2, 6);
        sendtowand(BR, 2);
        break;
      }
    case '3': {
        sendtowand(N3, 6);
        sendtowand(BR, 2);
        break;
      }
    case '4': {
        sendtowand(N4, 6);
        sendtowand(BR, 2);
        break;
      }
    case '5': {
        sendtowand(N5, 6);
        sendtowand(BR, 2);
        break;
      }
    case '6': {
        sendtowand(N6, 6);
        sendtowand(BR, 2);
        break;
      }
    case '7': {
        sendtowand(N7, 6);
        sendtowand(BR, 2);
        break;
      }
    case '8': {
        sendtowand(N8, 6);
        sendtowand(BR, 2);
        break;
      }
    case '9': {
        sendtowand(N9, 6);
        sendtowand(BR, 2);
        break;
      }
    case ':': {
        sendtowand(DOT, 2);
        sendtowand(BR, 2);
        break;
      }
    case ' ': {
        sendtowand(BR, 2);
        sendtowand(BR, 2);
        break;
      }
  }
}

void setup() {
  for (int i = 2; i < 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}
void loop()
{
  sendtowand(LOAD, 10);
  delay(refreshrate * 3);
  int len = str.length();
  for (int i = 0; i < len; i++) {
    disp(str[i]);
  }
}
