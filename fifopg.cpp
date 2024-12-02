#include <iostream>
using namespace std;

int main() {
    int numFrames, numPages;

    cout << "Enter number of frames: ";
    cin >> numFrames;
    cout << "Enter number of pages: ";
    cin >> numPages;

    int pages[numPages];
    cout << "Enter page references: ";
    for (int i = 0; i < numPages; i++) {
        cin >> pages[i];
    }

    int frames[numFrames];
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }

    int pageFaults = 0;
    int nextReplace = 0;  

    for (int i = 0; i < numPages; i++) {
        bool found = false;
        
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            pageFaults++;
            frames[nextReplace] = pages[i];
            nextReplace = (nextReplace + 1) % numFrames;
        }

        cout << "Frames: ";
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] != -1) {
                cout << frames[j] << " ";
            } else {
                cout << " - ";
            }
        }
        cout << endl;
    }

    cout << "Total page faults: " << pageFaults << endl;

    return 0;
}
