#defining the module to be compiled
defmodule CS431Examples do

  #defining the function to be ran
  def controlstructures do

    #setting up the variable that will get user input
    compare = IO.gets("Input a whole value between 1 and 100 > ") |> String.trim |> String.to_integer
    #IO.gets takes in a whole line as a string, while printing whatever you want to the screen
    #String.trim takes off the excess just down to the useful data (the user input)
    #String.to_integer turns the string that IO.gets got into an integer

    #if/else statements remain largely the same as in any other programming language
    #the one catch is NO ELIF/ELSE IF/ELSIF/etc. AND the conditional ends with the keyword 'end'
    if compare > 50 do
      IO.puts "Over half!"
    else
      IO.puts "Half or under!"
    end

    #unless/else is just the opposite of if/else
    unless compare < 25 do
      IO.puts "A quarter or over!"
    else
      IO.puts "Under a quarter!"
    end

    #cond executes the first conditional that comes back true and then ditches the rest (kind of rude)
    cond do
      compare > 75 -> IO.puts "More than three quarters!" #if the value is more than 75, the rest don't matter!
      compare > 50 -> IO.puts "More than half!"
      compare > 25 -> IO.puts "More than a quarter!"
      compare > 1 -> IO.puts "More than one!"
      true -> IO.puts "Default"
    end

    #case statements act like any other case/switch statement, the first value that the variable is equal to gets its code executed
    case compare do
      75 -> IO.puts "Exactly three quarters!"
      50 -> IO.puts "Exactly half!"
      25 -> IO.puts "Exactly one quarter!"
      1 -> IO.puts "Exactly one!"
      _ -> IO.puts "Default"
    end

    #no looping structures! for, while, do/while, etc can all go take a hike! Go recurse something instead (:
  end

  #defining the function to be run
  def controlstructures2 do
    #getting three integers from the user
    num1 = IO.gets("Input a whole value to start at > ") |> String.trim |> String.to_integer
    num2 = IO.gets("Input a whole value to end at > ") |> String.trim |> String.to_integer
    num3 = IO.gets("Input whether to count up by 1 or 2 > ") |> String.trim |> String.to_integer
    #putting all the of the integers into a list
    count = [num1, num2, num3]
    #calling the function "count_up"
    count_up(count)
    IO.puts "-------------------------------" #this is for flare and organization
    #calling the function "count_better" which will show off a simpler way to do recursion and flow control in Elixir
    count_better(count)
  end

  #defining the count_up function, which will count from one value to the next by a designated increment using flow control
  def count_up([min, max, inc]) do
    #the many if statements that come with recursive functions
    #if min is greater than or equal to max, enter the if
    if min >= max do
      #if min is exactly equal to max, print and exit
      if min == max do
        IO.puts min
      end
      #if min is greater than max, do not print - just exit
      nil
    else
      #if min is less than max, print min and then call another count_up, this time incrementing min by inc
      IO.puts min
      count_up([min + inc, max, inc])
    end
  end

  #defining the count_better function(s), which will count from one value to the next by a designated increment using Elixir's specialties
  #the first count_better will execute when min is greater than max, and it will do nothing
  def count_better([min, max, _]) when min > max, do: nil
  #the second count_better will execute when min is equal to max, and it will print min
  def count_better([min, max, _]) when min == max do
    IO.puts min
  end
  #the final count_better will execute when neither of the other two count_betters are true
  def count_better([min, max, inc]) do
    #this count_better will output min AND call count_better like a recursive function should
    IO.puts min
    count_better([min + inc, max, inc])
  end

end
