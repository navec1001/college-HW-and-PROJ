#defining a module holding our first custom Struct
defmodule StructEx do
  defstruct [:variable1, :variable2, :variable3] #this struct holds three variables with no required definitions by arguments!
end

#defining a new module holding our second custom Struct
defmodule StructEx2 do
  @enforce_keys [:variable1] #the first variable MUST be defined by the arguments in order to instantiate this struct
  defstruct [:variable1, variable2: 42, variable3: 96] #variables 2 and 3 have default values and do nothave to be defined by the arguments
end

#defining the module to be compiled
defmodule InterestingName do

  #defining the function to be executed
  def datastructures do

    #sampling a list and messing with it
    listex = [1, 2, 3]
    IO.inspect(listex)
    #adding 4, 5, 6 to our list
    listex1 = listex ++ [4, 5, 6]
    IO.inspect(listex1)
    # subtracting 2, 4, 6 from our list
    listex2 = listex1 -- [2, 4, 6]
    IO.inspect(listex2)
    #cutting off the head from the tail of our list
    [head|tail] = listex2
    IO.inspect(head)
    IO.inspect(tail)

    #sampling a tuple and outputting it
    tupex = {24, :funnier, 25, "haha"}
    IO.inspect(tupex, label: "This is a tuple: ")

    #sampling a keylist and outputting it
    keylist = [{:key1, "E"}, {:key2, 68}, {:ihavetobeanatom, :icanbewhatever}]
    IO.inspect(keylist, label: "This is a keylist: ")

    #records don't matter lol
    rec = "Records are something from Erlang, we don't really care"
    IO.puts rec

    #giving an example of a blank map
    blank_map = %{}
    IO.inspect(blank_map, label: "This is a blank map: ")

    #giving an example of a map with elements
    treasure_map = %{:arg => "yargh", "declaration" => "of independence", matey: 1542}
    IO.inspect(treasure_map, label: "Argh! This is me treasure map: ")

    #giving an example of a blank map being created using a function versus an assignment statement
    func_map = Map.new()
    IO.inspect(func_map, label: "This is a blank map created with a function: ")

    #giving an example of a map with elements using a function versus an assignment statement
    func_map_but_better = Map.new([{:outofjokes, "sorry y'all"}, {:toptext, "bottom text"}])
    IO.inspect(func_map_but_better, label: "This is a full map created with a function: ")

    #giving an example of creating a struct without inputting any arguments (FAIL!)
    good_name = %StructEx{}
    IO.inspect(good_name, label: "This is a blank struct: ")

    #giving an example of creating a struct while inputting arguments (phew!)
    gooder_name = %StructEx2{variable1: 59}
    IO.inspect(gooder_name, label: "This is a struct with an argument for the enforced key: ")

    #giving an example of creating a struct while inputting all arguments
    goodest_name = %StructEx2{variable1: 24, variable2: 55, variable3: 32}
    IO.inspect(goodest_name, label: "This is a struct with all arguments filled: ")

    #creating a stream (set of computations) that will cycle through 1, 2, 3 until a given stopping point...
    stream = Stream.cycle([1,2,3])
    #...and using Enum.takes to take 10 elements from the stream that cycles through 1, 2, 3 !!!
    Enum.take(stream, 10)

    #LARGE computations going on here, getting 1-100,000 and then multiplying everything by 3 and then getting the odd numbers
    #and then taking the first 10 odd numbers from the Stream using Enum.takes
    streamcomp = 1..100_000 |> Stream.map(&(&1 * 3)) |> Stream.filter(fn x -> rem(x,2) != 0 end) |> Enum.take(10)
    IO.inspect(streamcomp)

    #using streams to surround a file, meaning it will auto-open when needed and auto-close when done!
    streamfile = File.stream!("streamexample.txt")
    %File.Stream{
      line_or_bytes: :line,
      modes: [:raw, :read_ahead, :binary],
      path: "streamexample.txt",
      raw: true
    }
    #putting the stream's money where its mouth is with Enum.takes of course!
    Enum.take(streamfile, 10)
  end
end
