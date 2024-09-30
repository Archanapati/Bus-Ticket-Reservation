#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECIPES 100
#define MAX_NAME_LEN 50
#define MAX_INGREDIENTS 200
#define MAX_STEPS 500

typedef struct {
    char name[MAX_NAME_LEN];
    char ingredients[MAX_INGREDIENTS];
    char steps[MAX_STEPS];
} Recipe;

Recipe recipes[MAX_RECIPES];
int recipeCount = 0;

void addRecipe() {
    if (recipeCount >= MAX_RECIPES) {
        printf("Recipe book is full!\n");
        return;
    }
    
    printf("Enter recipe name: ");
    getchar(); // To consume leftover newline
    fgets(recipes[recipeCount].name, MAX_NAME_LEN, stdin);
    recipes[recipeCount].name[strcspn(recipes[recipeCount].name, "\n")] = 0; // Remove newline
    
    printf("Enter ingredients: ");
    fgets(recipes[recipeCount].ingredients, MAX_INGREDIENTS, stdin);
    recipes[recipeCount].ingredients[strcspn(recipes[recipeCount].ingredients, "\n")] = 0;
    
    printf("Enter steps: ");
    fgets(recipes[recipeCount].steps, MAX_STEPS, stdin);
    recipes[recipeCount].steps[strcspn(recipes[recipeCount].steps, "\n")] = 0;
    
    recipeCount++;
    printf("Recipe added successfully!\n");
}

void viewRecipes() {
    if (recipeCount == 0) {
        printf("No recipes available.\n");
        return;
    }

    for (int i = 0; i < recipeCount; i++) {
        printf("Recipe #%d: %s\n", i + 1, recipes[i].name);
        printf("Ingredients: %s\n", recipes[i].ingredients);
        printf("Steps: %s\n\n", recipes[i].steps);
    }
}

void searchRecipe() {
    char searchName[MAX_NAME_LEN];
    printf("Enter the name of the recipe to search: ");
    getchar(); // To consume leftover newline
    fgets(searchName, MAX_NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    for (int i = 0; i < recipeCount; i++) {
        if (strcmp(searchName, recipes[i].name) == 0) {
            printf("Recipe found: %s\n", recipes[i].name);
            printf("Ingredients: %s\n", recipes[i].ingredients);
            printf("Steps: %s\n\n", recipes[i].steps);
            return;
        }
    }
    printf("Recipe not found.\n");
}

void editRecipe() {
    char editName[MAX_NAME_LEN];
    printf("Enter the name of the recipe to edit: ");
    getchar(); // To consume leftover newline
    fgets(editName, MAX_NAME_LEN, stdin);
    editName[strcspn(editName, "\n")] = 0;

    for (int i = 0; i < recipeCount; i++) {
        if (strcmp(editName, recipes[i].name) == 0) {
            printf("Editing recipe: %s\n", recipes[i].name);
            
            printf("Enter new ingredients: ");
            fgets(recipes[i].ingredients, MAX_INGREDIENTS, stdin);
            recipes[i].ingredients[strcspn(recipes[i].ingredients, "\n")] = 0;

            printf("Enter new steps: ");
            fgets(recipes[i].steps, MAX_STEPS, stdin);
            recipes[i].steps[strcspn(recipes[i].steps, "\n")] = 0;

            printf("Recipe updated successfully!\n");
            return;
        }
    }
    printf("Recipe not found.\n");
}

void deleteRecipe() {
    char deleteName[MAX_NAME_LEN];
    printf("Enter the name of the recipe to delete: ");
    getchar(); // To consume leftover newline
    fgets(deleteName, MAX_NAME_LEN, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0;

    for (int i = 0; i < recipeCount; i++) {
        if (strcmp(deleteName, recipes[i].name) == 0) {
            for (int j = i; j < recipeCount - 1; j++) {
                recipes[j] = recipes[j + 1];
            }
            recipeCount--;
            printf("Recipe deleted successfully!\n");
            return;
        }
    }
    printf("Recipe not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Recipe Management System ---\n");
        printf("1. Add Recipe\n");
        printf("2. View Recipes\n");
        printf("3. Search Recipe\n");
        printf("4. Edit Recipe\n");
        printf("5. Delete Recipe\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecipe();
                break;
            case 2:
                viewRecipes();
                break;
            case 3:
                searchRecipe();
                break;
            case 4:
                editRecipe();
                break;
            case 5:
                deleteRecipe();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}