mutex mt;
condition_variable cv;
vector<char> buf;

void sending_thread()
{
	while(<some condition>)
	{
		unique_lock<mutex> 1(mt);
		while (buf.empty())
			cv.wait(1);
	//cv.wait(1,[](){return !buf.empty();})

	send((buf.data),buf.size())
	}
}


void on_frame(vector<char> const &data)
{
	{
		unique_lock <mutex> 1(mt);
		buf.insert(buf.end(), data.begin(),data.end())
	}
	cv.notify_one();
}