#include <iostream>
#include <string>
#include <vector>

class NutritionPlan {
private:
    int caloricIntake;
    int carbohydratesRatio;
    int proteinsRatio;
    int fatsRatio;
    std::vector<std::string> mealPlans;
    std::string fitnessGoal;
    std::vector<std::string> dietaryRestrictions;

public:
    void setCaloricIntake(int caloricIntake) {
        this->caloricIntake = caloricIntake;
    }

    void setMacronutrientRatios(int carbohydratesRatio, int proteinsRatio, int fatsRatio) {
        this->carbohydratesRatio = carbohydratesRatio;
        this->proteinsRatio = proteinsRatio;
        this->fatsRatio = fatsRatio;
    }

    void setMealPlans(const std::vector<std::string>& mealPlans) {
        this->mealPlans = mealPlans;
    }

    void setFitnessGoal(const std::string& fitnessGoal) {
        this->fitnessGoal = fitnessGoal;
    }

    void setDietaryRestrictions(const std::vector<std::string>& dietaryRestrictions) {
        this->dietaryRestrictions = dietaryRestrictions;
    }

    void display() {
        std::cout << "Nutrition Plan:\n";
        std::cout << "Caloric Intake: " << caloricIntake << " kcal\n";
        std::cout << "Macronutrient Ratios: Carbohydrates: " << carbohydratesRatio << "%, Proteins: " << proteinsRatio << "%, Fats: " << fatsRatio << "%\n";
        std::cout << "Meal Plans:\n";
        for (const auto& plan : mealPlans) {
            std::cout << "- " << plan << "\n";
        }
        std::cout << "Fitness Goal: " << fitnessGoal << "\n";
        std::cout << "Dietary Restrictions:\n";
        for (const auto& restriction : dietaryRestrictions) {
            std::cout << "- " << restriction << "\n";
        }
    }
};

class NutritionPlanBuilder {
protected:
    NutritionPlan nutritionPlan;

public:
    virtual void setCaloricIntake(int caloricIntake) = 0;
    virtual void setMacronutrientRatios(int carbohydratesRatio, int proteinsRatio, int fatsRatio) = 0;
    virtual void setMealPlans(const std::vector<std::string>& mealPlans) = 0;
    virtual void setFitnessGoal(const std::string& fitnessGoal) = 0;
    virtual void setDietaryRestrictions(const std::vector<std::string>& dietaryRestrictions) = 0;
    virtual NutritionPlan build() = 0;
};

class WeightLossNutritionPlanBuilder : public NutritionPlanBuilder {
public:
    void setCaloricIntake(int caloricIntake) override {
        nutritionPlan.setCaloricIntake(caloricIntake);
    }

    void setMacronutrientRatios(int carbohydratesRatio, int proteinsRatio, int fatsRatio) override {
        nutritionPlan.setMacronutrientRatios(carbohydratesRatio, proteinsRatio, fatsRatio);
    }

    void setMealPlans(const std::vector<std::string>& mealPlans) override {
        nutritionPlan.setMealPlans(mealPlans);
    }

    void setFitnessGoal(const std::string& fitnessGoal) override {
        nutritionPlan.setFitnessGoal(fitnessGoal);
    }

    void setDietaryRestrictions(const std::vector<std::string>& dietaryRestrictions) override {
        nutritionPlan.setDietaryRestrictions(dietaryRestrictions);
    }

    NutritionPlan build() override {
        return nutritionPlan;
    }
};

class NutritionPlanDirector {
private:
    NutritionPlanBuilder* builder;

public:
    void setBuilder(NutritionPlanBuilder* builder) {
        this->builder = builder;
    }

    NutritionPlan createNutritionPlan() {
        return builder->build();
    }
};

int main() {
    WeightLossNutritionPlanBuilder builder;

    NutritionPlanDirector director;
    director.setBuilder(&builder);

    builder.setCaloricIntake(2000);
    builder.setMacronutrientRatios(40, 30, 30);
    builder.setMealPlans({"Breakfast: Oatmeal", "Lunch: Chicken Salad", "Dinner: Grilled Salmon"});
    builder.setFitnessGoal("Weight Loss");
    builder.setDietaryRestrictions({"Gluten-free", "Lactose-free"});

    NutritionPlan nutritionPlan = director.createNutritionPlan();

    nutritionPlan.display();

    return 0;
}
