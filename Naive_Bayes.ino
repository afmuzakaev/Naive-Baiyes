const int numSamples = 100;
const int numFeatures = 2;
float features[numSamples][numFeatures];
int labels[numSamples];

void setup() {
  Serial.begin(9600);

  randomSeed(analogRead(0));  // Initialize random seed
  
  // Generate random training data
  for (int i = 0; i < numSamples; ++i) {
    features[i][0] = random(0, 100) / 100.0;
    features[i][1] = random(0, 100) / 100.0;
    labels[i] = features[i][0] + features[i][1] > 1.0 ? 1 : 0;
  }
}

void loop() {
  // Generate a random test input
  float testFeatures[numFeatures];
  testFeatures[0] = random(0, 100) / 100.0;
  testFeatures[1] = random(0, 100) / 100.0;

  // Predict the label using a simple rule (sum of features)
  int predictedLabel = testFeatures[0] + testFeatures[1] > 1.0 ? 1 : 0;

  Serial.print("Test Input: ");
  Serial.print(testFeatures[0]);
  Serial.print(", ");
  Serial.print(testFeatures[1]);
  Serial.print(" - Predicted Label: ");
  Serial.println(predictedLabel);

  delay(1000);  // Delay for a second
}
