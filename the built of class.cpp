class S
{
	enum class size1
	{
		small,
		medium,
		large,
	};
	enum class size2
	{
		small = 3,
		medium,
		large,
	};
	int arr[(unsigned long long)size2::large];
	std::string company;
	double share_val;
	long share;
	double total_val;
	void count_total()
	{
		total_val = share * share_val;
	}

public:

	S(const std::string& company_, long share_ = 0, double share_val_ = 0, double total_val_ = 0);
	S();
	~S();
	const S& topval(const S& s) const;
	void initial(std::string company_, long share_, double share_val_);
	void buy(long share_, double share_val);
	void sell(long share_, double share_val);
	void show() const;
	inline double rshare() const { return share; };
};

const S& S::topval(const S& s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

S::S()
{
	company = "no name";
	share = 0;
	share_val = 0;
	total_val = 0;
}

S::~S()
{
	std::cout << "bye" << company << std::endl;
}
S::S(const std::string& company_, long share_, double share_val_, double total_val_)
{
	company = company_;
	share = share_;
	share_val = share_val_;
	total_val = total_val_;
}

void S::initial(std::string company_, long share_, double share_val_)
{
	company = company_;
	share = share_;
	share_val = share_val_;
	count_total();
}
void S::buy(long share_, double share_val_)
{
	share += share_;
	share_val = share_val_;
	count_total();
}
void S::sell(long share_, double share_val_)
{
	share -= share_;
	share_val = share_val_;
	count_total();
}
void S::show() const
{
	std::cout << company << std::endl;
	std::cout << share << std::endl;
	std::cout << share_val << std::endl;
	std::cout << total_val << std::endl;
}
