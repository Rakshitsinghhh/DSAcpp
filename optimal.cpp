#include<iostream>
#include<vector>
using namespace std;

int main() {
    int numFrames, numPages;

    cout << "Enter number of frames: ";
    cin >> numFrames;
    cout << "Enter number of pages: ";
    cin >> numPages;

    vector<int> pages(numPages);
    cout << "Enter page references: ";
    for (int i = 0; i < numPages; i++) {
        cin >> pages[i];
    }

    vector<int> frames(numFrames, -1);  
    int pageFaults = 0;

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

            bool placed = false;
            for (int j = 0; j < numFrames; j++) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    placed = true;
                    break;
                }
            }

            if (!placed) {
                int farthest = -1, indexToReplace = -1;

                for (int j = 0; j < numFrames; j++) {
                    int nextUse = numPages;

                    for (int k = i + 1; k < numPages; k++) {
                        if (frames[j] == pages[k]) {
                            nextUse = k;
                            break;
                        }
                    }

                    if (nextUse == numPages) {
                        indexToReplace = j;
                        break;
                    }
                    
                    if (nextUse > farthest) {
                        farthest = nextUse;
                        indexToReplace = j;
                    }
                }

                frames[indexToReplace] = pages[i];
            }
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
