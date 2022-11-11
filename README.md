Класс Brute - реализует подбор паролей произвольной длинны из заданного набора символов.

void SetList(char from, char to) - метод добавляет к существующему набору все символы промежутке от from до to(включительно)

void SetList(std::string const& list) - тоже но набор идет из строки list

std::string& GetPassword() - главный метод класса - возвращает текущий сгенерированный пароль.
	внутри запоминается текущий перебор через поле size_t m_index
	поэтому рекомендуется запускать этот метод в цикле!
	
Как это работает?
Алгоритм перебора подобен счетчику 
Постоянно меняется самый левый(нулевой символ). После достижения последнего элемента из заданного списка - Нулевой элемент обнуляется(ему присваивается
самый первый элемент списка). И если до этого не было добавлено следующего правого символа - добавляется самый первый элемент из списка иначе этот
более правый элемент увеличивается(считывается из списка). И если этот элемент переполняется происходит тоже самое с более правым элементом и т.д.

Для определения нужного размера применяется метод size_t GetSize() const основанный на использовании свойств геометрической прогрессии,
а именно если n = 10;

То для перебора одно символьного пароля нужно - n итераций (10)
Для перебора дву символьного пароля - n + n * n - (10 + 10 * 10 = 110)
Для 3-х символьного - n + n * n + n * n * n - (10 + 10 * 10 + 10 * 10 * 10 = 1110)
