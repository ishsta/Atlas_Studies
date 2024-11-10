using Hangman.BLL;
using Xunit;

namespace Hangman.Tests;

public class GameTests
{
    [Fact]
    public void InitialStateTest()
    {
        // Arrange
        var game = new Game("apple");

        // Act & Assert
        Assert.False(game.IsGameOver);
        Assert.Equal(5, game.StrikesRemaining);
        Assert.Equal("_ _ _ _ _", string.Join(" ", game.CurrentGuess));
    }

    [Fact]
    public void SingleLetterGuessTest()
    {
        var game = new Game("apple", enableConsoleRead: false);
        int wins = 0;
        int losses = 0;

        game.ProcessGuess("a", "Player", ref wins, ref losses);

        Assert.Equal("a _ _ _ _", string.Join(" ", game.CurrentGuess));
        Assert.False(game.IsGameOver);
    }

    [Fact]
    public void WholeWordGuessTest()
    {
        var game = new Game("apple", enableConsoleRead: false);
        int wins = 0;
        int losses = 0;

        game.ProcessGuess("apple", "Player", ref wins, ref losses);

        Assert.True(game.IsGameOver);
        Assert.Equal(1, wins);
        Assert.Equal(0, losses);
    }

    [Fact]
    public void StrikesDepletedTest()
    {
        var game = new Game("apple", enableConsoleRead: false);
        int wins = 0;
        int losses = 0;

        game.ProcessGuess("x", "Player", ref wins, ref losses);
        game.ProcessGuess("y", "Player", ref wins, ref losses);
        game.ProcessGuess("z", "Player", ref wins, ref losses);
        game.ProcessGuess("q", "Player", ref wins, ref losses);
        game.ProcessGuess("w", "Player", ref wins, ref losses);

        Assert.True(game.IsGameOver);
        Assert.Equal(0, wins);
        Assert.Equal(1, losses);
    }

    [Fact]
    public void CorrectUpdateTest()
    {
        var game = new Game("apple", enableConsoleRead: false);
        int wins = 0;
        int losses = 0;

        game.ProcessGuess("a", "Player", ref wins, ref losses);
        game.ProcessGuess("p", "Player", ref wins, ref losses);

        Assert.Equal("a p p _ _", game.CurrentGuess);
        Assert.False(game.IsGameOver);
    }
}