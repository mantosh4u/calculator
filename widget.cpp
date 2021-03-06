#include"widget.h"
#include"expression.h"

//To find out whether items are in the composite objects
class Name_Equal {
private:
    std::string val;
public:
    Name_Equal(const std::string& v) :val(v) { }
    bool operator()(Gtk::Widget* x) const { 
        return (x->get_name() == val); 
    }
};



/*************************************************************************************************/
void Updatedirector::WidgetChanged(Gtk::Widget* w) 
{
		std::string name = w->get_name();

		 //Check whether "=" widgets is cached or not.
			if(_equalButton == nullptr)
			{
				Name_Equal equal(std::string{"="}); 
				auto itrpos = std::find_if(std::begin(_widgetcolletion), std::end(_widgetcolletion),equal);
				if (itrpos != std::end(_widgetcolletion)) {
   				_equalButton = *itrpos;
				} 
			}
			
			// Check Whether "OutputDisplay" widgets is cached or not
			if(_entrySection == nullptr)
			{
				Name_Equal entry(std::string{"OutputDisplay"});
				auto itrpos = std::find_if(std::begin(_widgetcolletion), std::end(_widgetcolletion), entry);	
				if(itrpos != std::end(_widgetcolletion)) {
					_entrySection = *itrpos;				
				}
			}			
	

		// For time being I think there should be only two cases One when user presses oher 
      // than = button and Second is of course = button.		
		
		if((_entrySection != nullptr)&&(_equalButton != nullptr)) {
			_expression += name;
			entry* entryWidget = dynamic_cast<entry*>(_entrySection);
			if(entryWidget) {			
				entryWidget->set_text(_expression);
			}						
		}
						
		if(name.compare("=") == 0)
		{
			expression e{_expression};
			auto output = e.evalute();
			_output = std::to_string(output);
			entry* entryWidget = dynamic_cast<entry*>(_entrySection);
			if(entryWidget) {			
				entryWidget->set_text(_output);
			}
			// Now Reset the expression with the output so that it can be used
			// in continuation.
			_expression = _output; 						
		}
}


void Updatedirector::GetWidgets(Gtk::Widget* w) 
{
	_widgetcolletion.push_back(w);
}



/*************************************************************************************************/

button::button()
{
	signal_clicked().connect(sigc::mem_fun(*this, &button::on_button_clicked) );
}


void button::set_name_button(std::string label)
{
	add_label(label);
	set_name(label);
}

void button::set_director(director* d) 
{
	_director = d;
	_director->GetWidgets(this);
}

void button::on_button_clicked(void)
{
	// Notify Director that I am changed
   _director->WidgetChanged(this);
}


/*************************************************************************************************/

entry::entry()
{
	set_size_request(200,100);
	//signal_clicked().connect(sigc::mem_fun(*this, &entry::on_button_close) );
}

void entry::set_name_entry(std::string label)
{
	set_name(label);
}

void entry::set_director(director* d)
{
   _director = d;
	_director->GetWidgets(this);
   _director->WidgetChanged(this);
}


void entry::on_button_close(void)
{
	display("Button Close");
	// Notify Director that I am changed
	_director->WidgetChanged(this);
}



/*************************************************************************************************/

rowpack::rowpack()
{
	// now pack all objects into one
	row_object.pack_start(m_one);
	row_object.pack_start(s_one);

	row_object.pack_start(m_two);	
	row_object.pack_start(s_two);
	
	row_object.pack_start(m_three);
	row_object.pack_start(s_three);

	row_object.pack_start(m_four);
	row_object.pack_start(s_four);
	
	row_object.pack_start(m_five);
	row_object.pack_start(s_five);

	row_object.pack_start(m_six);	
}



void rowpack::intialize(std::vector<std::string>& label,director* d)
{
	auto sz = label.size();
	decltype(sz) index{};
	
	
	if(index < sz) {
		m_one.set_name_button(label.at(index) );
		m_one.set_director(d);
		index = index + 1;
	}
	
	if(index < sz) {
		m_two.set_name_button(label.at(index) );
		m_two.set_director(d);		
		index = index + 1;
	}
	
	if(index < sz) {
		m_three.set_name_button(label.at(index) );
		m_three.set_director(d);		
		index = index + 1;
	}

	if(index < sz) {
		m_four.set_name_button(label.at(index) );
		m_four.set_director(d);	
		index = index + 1;
	}
		
	if(index < sz) {
		m_five.set_name_button(label.at(index) );
		m_five.set_director(d);		
		index = index + 1;
	}
	
	if(index < sz) {
		m_six.set_name_button(label.at(index) );
		m_six.set_director(d);		
		index = index + 1;
	}
	
}




/*************************************************************************************************/
calculator::calculator()
{
	std::string title {"calculator"};
	set_title(title);
	set_size_request(600, 100);
   gdirector = new Updatedirector();
}


calculator::~calculator() 
{
	delete gdirector;
}

void calculator::run(void)
{	

	// manage display object 
	column_object.pack_start(displ_area);
	column_object.pack_start(displ_sep);
	
 	displ_area.set_name_entry("OutputDisplay");
	// Update this widget information to Updatedirector
	displ_area.set_director(gdirector);	

	// manage first row object
	std::vector<std::string> rone_label{ "7", "8", "9", "/", "bksp", "**"};
	first_robject.intialize(rone_label, gdirector);
	
	// add the first row object to the main column object
	column_object.pack_start(first_robject.row_object);
	column_object.pack_start(first_sep);


	// manage second row object
	std::vector<std::string> rtwo_label{ "4", "5", "6", "*", "(", ")"};
	second_robject.intialize(rtwo_label, gdirector);

	// add the second row object to the main column object
	column_object.pack_start(second_robject.row_object);
	column_object.pack_start(second_sep);


	// manage third row object
	std::vector<std::string> rthird_label{ "1", "2", "3", "-", "x^2", "sqrt"};
	third_robject.intialize(rthird_label, gdirector);

	// add the second row object to the main column object
	column_object.pack_start(third_robject.row_object);
	column_object.pack_start(third_sep);


	// manage four row object
	std::vector<std::string> rfourth_label{ "0", ".", "%", "+", "=", "empt"};
	fourth_robject.intialize(rfourth_label, gdirector);
	
	// add the second row object to the main column object
	column_object.pack_start(fourth_robject.row_object);


	add(column_object);
	
	show_all_children();

}
