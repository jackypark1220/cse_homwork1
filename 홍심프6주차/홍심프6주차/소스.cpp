#include <iostream>
#include <string>
#include<vector>
	class DrawInYellow
	{
	public:
		void draw()
		{
			std::cout << "Draw in Yello" << std::endl;
		}
	};

	class DrawInRed
	{
	public:
		void draw()
		{
			std::cout << "Draw in Red" << std::endl;
		}
	};
	class GeometricObjectInterface
	{
	public:
		virtual void draw() = 0;
	};
	template<class T_HOW_TO_DRAW>
	class GeometricObject : public GeometricObjectInterface

	{
	public:
		void draw()
		{
			T_HOW_TO_DRAW draw_in_color;
			draw_in_color.draw();
		}
	};

	int main()
	{ 
		std::vector<GeometricObjectInterface*> obj_list;
		obj_list.push_back(new GeometricObject<DrawInYellow>);
		obj_list.push_back(new GeometricObject<DrawInRed>);
		
		for (auto itr : obj_list)
		{
			itr->draw();
		}

		

		return 0;
	}