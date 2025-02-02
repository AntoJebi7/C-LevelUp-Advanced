#include <stdio.h>

// Define the enum for Traffic Light states
enum TrafficLight {
    RED = 1,    // Stop
    YELLOW = 2, // Prepare to Stop
    GREEN = 3   // Go
};

// Function to return the string representation of the traffic light state
const char* getTrafficLightAction(enum TrafficLight light) {
    switch (light) {
        case RED:
            return "Stop!";
        case YELLOW:
            return "Prepare to stop!";
        case GREEN:
            return "Go!";
        default:
            return "Invalid traffic light.";
    }
}

int main() {
    // Declare an enum variable for traffic light
    enum TrafficLight light;

    // Set the traffic light state to GREEN
    light = GREEN;

    // Check the action based on the traffic light state
    printf("Traffic Light: %s\n", getTrafficLightAction(light)); // Output: Traffic Light: Go!

    // Set the traffic light state to YELLOW
    light = YELLOW;
    printf("Traffic Light: %s\n", getTrafficLightAction(light)); // Output: Traffic Light: Prepare to stop!

    // Set the traffic light state to RED
    light = RED;
    printf("Traffic Light: %s\n", getTrafficLightAction(light)); // Output: Traffic Light: Stop!

    return 0;
}
