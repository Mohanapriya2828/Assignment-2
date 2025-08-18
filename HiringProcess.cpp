#include <iostream>
using namespace std;

int main() {
    cout << "Define job description\n";
    cout << "Send crew request to HR\n";

    char isRegularHiring;
    cout << " Is this a regular hiring process? (y/n): ";
    cin >> isRegularHiring;

    if (isRegularHiring == 'n' || isRegularHiring == 'N') {
        cout << "Special hiring process\n";
        cout << "Post job internally\n";
        return 0;
    }

    char isResumeCandidate;
    cout << " Is there a suitable candidate? (y/n): ";
    cin >> isResumeCandidate;

    if (isResumeCandidate == 'n' || isResumeCandidate == 'N') {
        char isQualifiedResume;
        cout << "Develop recruitment plan\n";
        cout << "Place advertisements\n";
        cout << "Collect applications\n";
        cout << "Is there a suitable candidate? (y/n): ";
        cin >> isQualifiedResume;

        if (isQualifiedResume == 'n' || isQualifiedResume == 'N') {
            cout << "Candidate not hired\n";
            cout << "Return\n";
            return 0;
        }

        cout << "Arrange candidate meeting\n";
    } else {
        cout << "Arrange candidate meeting\n";
    }

    cout << "Conduct pre-interview\n";
    cout << "Setup interview question\n";
    cout << "Conduct interview\n";

    char referenceGood;
    cout << "Good reference? (y/n): ";
    cin >> referenceGood;
    if (referenceGood == 'n' || referenceGood == 'N') {
        cout << "Candidate not hired\n";
        cout << "Return\n";
        return 0;
    }

    cout << "Select candidate\n";
    cout << "Evaluate pay rate\n";
    cout << "Send Employment offer\n";

    char offerConfirmed;
    cout << "Candidate confirms offer? (y/n): ";
    cin >> offerConfirmed;

    if (offerConfirmed == 'n' || offerConfirmed == 'N') {
        cout << "Candidate not hired\n";
        cout << "Return\n";
        return 0;
    }

    cout << "Hire candidate\n";
    return 0;
}