#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

class User
{
private:
    string username;
    string password;
    int age;
    float height;
    float weight;
    int healthCondition;

public:
    User(string _username, string _password, int _age, float _height, float _weight, int _healthCondition)
        : username(_username), password(_password), age(_age), height(_height), weight(_weight), healthCondition(_healthCondition) {}

    string getUsername() const
    {
        return username;
    }

    bool checkPassword(string _password) const
    {
        return password == _password;
    }

    double calculateBMI() const
    {
        return weight / pow(height / 100, 2); // Convert height from cm to meters
    }

    int getHealthCondition() const
    {
        return healthCondition;
    }

    int getAge() const
    {
        return age;
    }

    void displayUserInfo() const
    {
        cout << "---------------------------------------------" << endl;
        cout << "| Username: " << username << "                          |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| Age: " << age << "                                  |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| Height: " << height << " cm                         |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| Weight: " << weight << " kg                         |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| BMI: " << calculateBMI() << "                           |" << endl;
        cout << "---------------------------------------------" << endl;
    }
};

class Food
{
private:
    string name;
    int calories;
    int carbs;
    int protein;
    int vitamins;

public:
    Food(string _name, int _calories, int _carbs, int _protein, int _vitamins)
        : name(_name), calories(_calories), carbs(_carbs), protein(_protein), vitamins(_vitamins) {}

    string getName() const
    {
        return name;
    }

    int getCalories() const
    {
        return calories;
    }

    int getCarbs() const
    {
        return carbs;
    }

    int getProtein() const
    {
        return protein;
    }

    int getVitamins() const
    {
        return vitamins;
    }
};

class DietTracker
{
private:
    vector<Food> foods;
    int totalCalories;
    int totalCarbs;
    int totalProtein;
    int totalVitamins;

public:
    DietTracker() : totalCalories(0), totalCarbs(0), totalProtein(0), totalVitamins(0) {}

    void addFood(const Food& food)
    {
        foods.push_back(food);
        totalCalories += food.getCalories();
        totalCarbs += food.getCarbs();
        totalProtein += food.getProtein();
        totalVitamins += food.getVitamins();
    }

    void display() const
    {
        cout << "---------------------------------------------" << endl;
        cout << "| Diet Tracker:                             |" << endl;
        cout << "---------------------------------------------" << endl;
        for (const auto& food : foods)
        {
            cout << "| Food: " << food.getName() << ", Calories: " << food.getCalories()
                << ", Carbs: " << food.getCarbs() << "g, Protein: " << food.getProtein()
                << "g, Vitamins: " << food.getVitamins() << " IU             |" << endl;
            cout << "---------------------------------------------------------" << endl;
        }
        cout << "| Total Calories: " << totalCalories << "                   |" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "| Total Carbs: " << totalCarbs << "g                        |" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "| Total Protein: " << totalProtein << "g                    |" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "| Total Vitamins: " << totalVitamins << " IU                |" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
};

bool login(const vector<User>& users, string username, string password)
{
    for (const auto& user : users)
    {
        if (user.getUsername() == username && user.checkPassword(password))
        {
            return true;
        }
    }
    return false;
}

int startup()
{
    int n;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "|                                        EASY FIT                                  |" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "|                                  NUTRITION AND DIET PLANNER                      |" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| CHOOSE WHAT YOU WANT TO DO                |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| 1. LOGIN                                  |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| 2. REGISTER                               |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| 3. GET INFO                               |" << endl;
    cout << "---------------------------------------------" << endl;
    cin >> n;
    cout << "---------------------------------------------" << endl;
    return n;
}

void registerUser(vector<User>& users)
{
    string username, password;
    int age, choice;
    float height, weight;

    cout << "---------------------------------------------" << endl;
    cout << "| Enter Username:                           |" << endl;
    cout << "---------------------------------------------" << endl;
    cin >> username;
    cout << "---------------------------------------------" << endl;
    cout << "| Enter Password:                           |" << endl;
    cout << "---------------------------------------------" << endl;
    cin >> password;
    cout << "---------------------------------------------" << endl;
    cout << "| Enter Age:                                |" << endl;
    cout << "---------------------------------------------" << endl;
    cin >> age;
    cout << "---------------------------------------------" << endl;
    cout << "| Enter Height (in cm):                     |" << endl;
    cout << "---------------------------------------------" << endl;
    cin >> height;
    cout << "---------------------------------------------" << endl;
    cout << "| Enter Weight (in kg):                     |" << endl;
    cout << "---------------------------------------------" << endl;
    cin >> weight;

    cout << "----------------------------------------------------" << endl;
    cout << "| Choose from the below if anyone matches your     |" << endl;
    cout << "| health condition:                                |" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "| 1. Athlete                                |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| 2. Diabetes Patient                       |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| 3. Heart Patient                          |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| 4. Allergy (Vegetarian)                   |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| 5. Allergy (Non-Vegetarian)               |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| 6. None                                   |" << endl;
    cout << "---------------------------------------------" << endl;
    cin >> choice;

    users.push_back(User(username, password, age, height, weight, choice));
    cout << "\t\t\t\t ----------------------------------------------" << endl;
    cout << "\t\t\t\t|        User Registered Successfully         |" << endl;
    cout << "\t\t\t\t ----------------------------------------------" << endl;
    cout << "\t\t\t\t| You need to login back for smooth operation| " << endl;
    cout << "\t\t\t\t  -----------------------------------------------" << endl;
}

void generalinfo()
{
    char n;
    cout << "---------------------------------------------" << endl;
    cout << "| What you want to know about diet?         |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| a. Healthy BMI                            |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| b. Maintain BMI                           |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| c. For Blood Pressure Patient             |" << endl;
    cout << "---------------------------------------------" << endl;
    cin >> n;
    switch (n)
    {
    case 'a':
        cout << "---------------------------------------------" << endl;
        cout << "| The range considered healthy varies slightly| " << endl;
        cout << "| depending on the source, but generally:     |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 1. BMI below 18.5 is considered underweight |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 2. BMI between 18.5 and 24.9 is healthy     |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 3. BMI between 25 and 29.9 is overweight    |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 4. BMI of 30 or above is obese              |" << endl;
        cout << "---------------------------------------------" << endl;
        break;
    case 'b':
        cout << "---------------------------------------------" << endl;
        cout << "| To maintain a healthy BMI:                  |" << endl;
        cout << "| 1. Balanced diet                            |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 2. Regular physical activity                |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 3. Monitor calorie intake                   |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 4. Stay hydrated                            |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 5. Get enough sleep                         |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 6. Manage stress                            |" << endl;
        cout << "---------------------------------------------" << endl;
        break;
    case 'c':
        cout << "---------------------------------------------" << endl;
        cout << "| For individuals with high blood pressure:   |" << endl;
        cout << "| 1. Eat more fruits, vegetables, and low-fat |" << endl;
        cout << "|    dairy products                           |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 2. Reduce intake of saturated fat and salt  |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 3. Avoid excessive alcohol consumption      |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 4. Regular exercise                         |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| 5. Maintain a healthy weight                |" << endl;
        cout << "---------------------------------------------" << endl;
        break;
    default:
        cout << "---------------------------------------------" << endl;
        cout << "| Invalid choice                             |" << endl;
        cout << "---------------------------------------------" << endl;
        break;
    }
}

void displayDietPlan(const User& user)
{
    map<int, string> healthConditionMap = {
        {1, "Athlete"},
        {2, "Diabetes Patient"},
        {3, "Heart Patient"},
        {4, "Allergy (Vegetarian)"},
        {5, "Allergy (Non-Vegetarian)"},
        {6, "None"}
    };

    cout << "-------------------------------------------------------------------------" << endl;
    cout << "|             Generating Diet Plan based on health                      |" << endl;
    cout << "| condition: " << healthConditionMap[user.getHealthCondition()] << "    |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    // Mock diet plan, this should be replaced with actual logic
    cout << "| Breakfast: Oatmeal with fruits             |" << endl;
    cout << "| Lunch: Grilled chicken salad               |" << endl;
    cout << "| Dinner: Steamed vegetables and fish        |" << endl;
    cout << "| Snacks: N2uts and fruits                    |" << endl;
    cout << "---------------------------------------------" << endl;
}

void dietMenu(User& user)
{
    DietTracker dietTracker;
    char choice;
    do {
        cout << "---------------------------------------------" << endl;
        cout << "| Choose an option:                          |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| a. Calculate BMI                           |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| b. Generate Diet Plan                      |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| c. Go Back                                 |" << endl;
        cout << "---------------------------------------------" << endl;
        cin >> choice;

        switch (choice)
        {
        case 'a':
            cout << "---------------------------------------------" << endl;
            cout << "| Your BMI is: " << user.calculateBMI() << "                        |" << endl;
            cout << "---------------------------------------------" << endl;
            break;
        case 'b':
            displayDietPlan(user);
            break;
        case 'c':
            cout << "---------------------------------------------" << endl;
            cout << "| Returning to previous menu                 |" << endl;
            cout << "---------------------------------------------" << endl;
            return;
        default:
            cout << "---------------------------------------------" << endl;
            cout << "| Invalid choice                             |" << endl;
            cout << "---------------------------------------------" << endl;
            break;
        }
    } while (true);
}

int main()
{
    vector<User> users;
    vector<Food> foods = {
        Food("Apple", 95, 25, 0, 54),
        Food("Banana", 105, 27, 1, 88),
        Food("Chicken Breast", 165, 0, 31, 0),
        Food("Broccoli", 55, 11, 4, 81)
    };

    DietTracker dietTracker;
    for (const auto& food : foods)
    {
        dietTracker.addFood(food);
    }

    while (true)
    {
        int n = startup();
        switch (n)
        {
        case 1:
        {
            string username, password;
            cout << "---------------------------------------------" << endl;
            cout << "| Enter Username:                           |" << endl;
            cout << "---------------------------------------------" << endl;
            cin >> username;
            cout << "---------------------------------------------" << endl;
            cout << "| Enter Password:                           |" << endl;
            cout << "---------------------------------------------" << endl;
            cin >> password;

            if (login(users, username, password))
            {
                cout << "---------------------------------------------" << endl;
                cout << "| Login Successful                          |" << endl;
                cout << "---------------------------------------------" << endl;
                User* loggedInUser = nullptr;
                for (auto& user : users)
                {
                    if (user.getUsername() == username)
                    {
                        loggedInUser = &user;
                        break;
                    }
                }

                if (loggedInUser)
                {
                    loggedInUser->displayUserInfo();
                    dietMenu(*loggedInUser);
                }
            }
            else
            {
                cout << "---------------------------------------------" << endl;
                cout << "| Invalid Username or Password              |" << endl;
                cout << "---------------------------------------------" << endl;
            }
            break;
        }
        case 2:
            registerUser(users);
            break;
        case 3:
            generalinfo();
            break;
        default:
            cout << "---------------------------------------------" << endl;
            cout << "| Invalid choice                            |" << endl;
            cout << "---------------------------------------------" << endl;
            break;
        }
    }

    return 0;
}
