s = input();
w = ["Sunny", "Cloudy", "Rainy"];
print(w[(w.index(s)+1)%len(w)]);
