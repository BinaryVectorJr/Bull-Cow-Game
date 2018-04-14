#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All values initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessWordStatus
{
	Invalid,																//Always try to give first error as Invalid
	OK,
	Case_Mismatch,
	Wrong_Length,
	Not_Isogram,
};

class FBullCowGame
{
public:
	FBullCowGame();															//Constructor Initialized

	int32 GetMaxTries() const;												//Methods are like variable names only with () at the end
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessWordStatus CheckGuessValidity(FString) const;
	
	void Reset();															//all these functions are called a METHOD

	//once a valid guess comes in update the number of tries
	FBullCowCount SubmitValidGuess(FString Guess);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameWon;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};