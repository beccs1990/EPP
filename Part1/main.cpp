#include <iostream>
using namespace std;

// function prototypes
float findAverageScore(int size, int jScores[]);
void insertionSort(int size, int arr[]);

int main() {
    int judges, contestantNum, leadingContestant;
    float highestScore = 0.0, currentAverage;

    cout << "Enter number of judges: ";
    cin >> judges;
    int *scores = new int[judges];

    cout << "Enter the contestants number: ";
    cin >> contestantNum;
    // set first contestant as there are no others for comparison
    leadingContestant = contestantNum;

    // Continue loop for entering contestant number and scores while number is not negative
    while (contestantNum >= 0) {
        cout << "Enter all scores for contestant number " << contestantNum << ": ";
        for (int i = 0; i < judges; i++) {
            cin >> scores[i];
        }
        currentAverage = findAverageScore(judges, scores);
        cout << endl << "Contestant " << contestantNum << " " << currentAverage << endl;
        // update if current contestants average is higher than the previous saved high score
        if (currentAverage > highestScore) {
            highestScore = currentAverage;
            leadingContestant = contestantNum;
        }
        cout << "Enter next contestant number: ";
        cin >> contestantNum;
    }

    cout << "Contestant " << leadingContestant << " had the highest score." << endl;

    return 0;
}

/**
 * Function to find average minus the highest/lowest scores in array
 * Takes in two params for size of array and array of scores
 * Return value is floating point average of size-2
 */
float findAverageScore(int size, int jScores[]) {
    int total = 0;
    // call function to get sorted array of scores
    insertionSort(size, jScores);
    for (int i = 1; i <= size - 2; i++) {
        total += jScores[i];
    }
    return (float)total / (float)(size - 2);
}

void insertionSort(int size, int arr[]) {
    int i, j, next;
    for (i = 1; i < size; i++) {
        next = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > next) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = next;
    }
}