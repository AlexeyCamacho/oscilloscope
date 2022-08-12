#pragma once
#include"cmath"
#include"fstream"
#include"string"
#include <stdio.h>
#include <msclr\marshal_cppstd.h>


namespace oscilloscope {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			pw = pictureBox1->Width, ph = pictureBox1->Height;
			init_parametrsX();
			Function^ f = gcnew Function(this, &MyForm::f);
			y1 = y2 = f(x1);
			for (double x = x1; x <= x2; x += xstep) {
				double y = f(x); if (y > y2) y2 = y; if (y < y1) y1 = y;
			}
			init_parametrsY();
			this->pictureBox1->Image = init_Grid();
			startX = x2;
			generate_Point();

		}

	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::IO::FileSystemWatcher^ fileSystemWatcher1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Timer^ timer1;

	private: System::ComponentModel::IContainer^ components;


	private:


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(798, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(79, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"OFF";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::Color::LimeGreen;
			this->button2->Location = System::Drawing::Point(709, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(83, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"ON";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button5->Location = System::Drawing::Point(369, 522);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(22, 22);
			this->button5->TabIndex = 5;
			this->button5->Text = L"+";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button6->Location = System::Drawing::Point(341, 522);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(22, 22);
			this->button6->TabIndex = 6;
			this->button6->Text = L"-";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(5, 233);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(22, 22);
			this->button7->TabIndex = 7;
			this->button7->Text = L"+";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(5, 261);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(22, 22);
			this->button8->TabIndex = 8;
			this->button8->Text = L"-";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(714, 118);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Амплитуда (100-10000)";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(714, 187);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Частота (1-100) ";
			// 
			// button9
			// 
			this->button9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button9->AutoSize = true;
			this->button9->Location = System::Drawing::Point(716, 261);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(159, 48);
			this->button9->TabIndex = 13;
			this->button9->Text = L"Применить";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(33, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(657, 504);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			this->pictureBox1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseWheel);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(714, 349);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 14;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown1->Location = System::Drawing::Point(716, 145);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(159, 20);
			this->numericUpDown1->TabIndex = 15;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown2->Location = System::Drawing::Point(716, 212);
			this->numericUpDown2->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(159, 20);
			this->numericUpDown2->TabIndex = 16;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button4->Location = System::Drawing::Point(798, 51);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(79, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Открыть";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button3->Location = System::Drawing::Point(710, 51);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(82, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Сохранить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"txt";
			this->saveFileDialog1->FileName = L"test";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			this->timer1->Interval = 50;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(887, 550);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"Осциллограф";
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		delegate double Function(double);
		double f(double x) { return Math::Sin(F * x) * Amp; }

		const double zoomX = 1.1, zoomY = 1.1;

		int pw, ph, F = 1;
		bool move = false, ON = false;

		double x1 = -2 * Math::PI, x2 = 0, startX;
		double xstep, y1, y2, ystep, xcoeff, ycoeff, ox, oy;
		double coeff_GridX = 0.5, coeff_GridY = 1, Amp = 100;
		double shift = 0;

		System::Collections::Generic::List <PointF>^ Points = gcnew System::Collections::Generic::List <PointF>();


		Brush^ br = Brushes::Black;
		System::Drawing::Font^ fn = gcnew System::Drawing::Font(FontFamily::GenericSansSerif, 8.0F, FontStyle::Bold);

		Bitmap^ init_Grid() { // Рисование сетки
			Bitmap^ img = gcnew Bitmap(pw, ph);
			Graphics^ g = Graphics::FromImage(img);
			double mx = -x1 * xcoeff, my = -y1 * ycoeff;


			edit_Coeff_Grid();

			double koord = 0;
			for (double i = my; i < ph; i += Amp / 4 * ycoeff * coeff_GridY) {
				g->DrawLine(Pens::Blue, 0, i, pw, i);
				if (koord == 0) {
					g->DrawString(koord.ToString(), fn, br, 0, i - 14);
				}
				else {
					g->DrawString(koord.ToString(), fn, br, 0, i);
				}
				koord -= (Amp / 4 * coeff_GridY);
			};

			koord = 0;
			for (double i = my; i > -ph / 2; i -= Amp / 4 * ycoeff * coeff_GridY) {
				g->DrawLine(Pens::Blue, 0, i, pw, i);
				if (koord != 0) {
					g->DrawString(koord.ToString(), fn, br, 0, i);
				}
				koord += (Amp / 4 * coeff_GridY);
			}

			koord = 0;
			for (double i = mx; i < pw; i += Math::PI / F * xcoeff * coeff_GridX) {
				g->DrawLine(Pens::Blue, i, 0, i, ph);
				g->DrawString((round(koord * 100) / 100).ToString(), fn, br, i, my);
				koord += (Math::PI / F * coeff_GridX);
			}

			koord = 0;
			for (double i = mx; i > -pw / 2; i -= Math::PI / F * xcoeff * coeff_GridX) {
				g->DrawLine(Pens::Blue, i, 0, i, ph);
				g->DrawString((round(koord * 100) / 100).ToString(), fn, br, i, my);
				koord -= (Math::PI / F * coeff_GridX);
			}

			g->DrawLine(Pens::Red, 0, 0, 0, ph);
			g->DrawLine(Pens::Red, 0, my, pw, my);

			this->pictureBox1->Image = img;
			return img;
		}

		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // OFF
			this->timer1->Enabled = false;
			ON = false;
		}

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // ON
			this->timer1->Enabled = true;
			ON = true;
			edit_Paraneters();
			drow_Graf();
		}

		void edit_Paraneters() { // Изменение параметров
			F = (int)this->numericUpDown2->Value;
			Amp = (int)this->numericUpDown1->Value;
		}

		void drow_Graf() { // Построение графика
			Graphics^ g = Graphics::FromImage(init_Grid());

			System::Collections::Generic::List <PointF>^ View_Points = 
				gcnew System::Collections::Generic::List <PointF>();

			if (!move && ON) {
				generate_Point();
			}

			for each (PointF point in Points)
			{
				if (point.X > x1 && point.X < x2) {
					View_Points->Add(PointF((point.X - x1) * xcoeff, (-point.Y - y1) * ycoeff));
				}

				if (point.X >= x2) { break; }
			}

			if (View_Points->Count > 2) {
				g->DrawLines(Pens::Green, View_Points->ToArray());
			}

		}

		void generate_Point() { // генерация точки
			double y = f(startX);
			Points->Add(PointF(startX, y)); startX += xstep;
		}

		System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) { // Применить
			edit_Paraneters();
			drow_Graf();
		}

		System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { // + Х
			x1 /= zoomX;
			x2 /= zoomX;
			zoomingX();
		}

		System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) { // - Х
			x1 *= zoomX;
			x2 *= zoomX;
			zoomingX();
		}

		System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) { // + Y
			y1 /= zoomY;
			y2 /= zoomY;
			zoomingY();
		}

		System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) { // - Y
			y1 *= zoomY;
			y2 *= zoomY;
			zoomingY();
		}

		void init_parametrsX() { // Пересчет параметров абсцисс
			xstep = (x2 - x1) / pw;
			xcoeff = pw / (x2 - x1);
		}

		void init_parametrsY() { // Пересчет параметров ординат
			ystep = (y2 - y1) / ph;
			ycoeff = ph / (y2 - y1);
		}

		void zoomingX() { // Масштабирование по X
			ON = false;
			init_parametrsX();
			drow_Graf();
			ON = true;
		}

		void zoomingY() { // Масштабирование по Y
			ON = false;
			init_parametrsY();
			drow_Graf();
			ON = true;
		}

		void edit_Coeff_Grid() { // Изменение сетки
			if (!move) {
				double y = Amp / 4 * ycoeff * coeff_GridY;
				double x = Math::PI / F * xcoeff * coeff_GridX;

				if ((ph / y) > 12) { coeff_GridY *= 2; }
				else if ((ph / y) < 4) { coeff_GridY /= 2; }

				if ((pw / x) > 12) { coeff_GridX *= 2; }
				else if ((pw / x) < 4) { coeff_GridX /= 2; }
			}
		}

		System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { // Нажатие ЛКМ
			this->timer1->Enabled = false;
			move = true;
			ox = e->X;
			oy = e->Y;
		}

		System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { // Отжатие ЛКМ
			if (ON) { this->timer1->Enabled = true; }
			move = false;
		}

		System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { // перемещение

			if (move) {
				double dx = e->X - ox;
				double dy = e->Y - oy;
				x1 -= dx / xcoeff;
				x2 -= dx / xcoeff;
				y1 -= dy / ycoeff;
				y2 -= dy / ycoeff;
				ox = e->X;
				oy = e->Y;
				drow_Graf();
			}

		}

		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { // Открыть
			this->button1_Click(sender, e);
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) { return; }
			std::string filename = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
			std::ifstream file;
			file.open(filename);
			std::string line;

			getline(file, line); x1 = atof(line.c_str());
			getline(file, line); x2 = atof(line.c_str());
			getline(file, line); y1 = atof(line.c_str());
			getline(file, line); y2 = atof(line.c_str());
			getline(file, line); startX = atof(line.c_str());


			std::string lineX;
			std::string lineY;

			Points->Clear();

			while (getline(file, lineX))
			{
				getline(file, lineY);
				Points->Add(PointF(std::stod(lineX), std::stod(lineY)));

			}

			file.close();

			init_parametrsX();
			init_parametrsY();

			drow_Graf();

		}

		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // Сохранить
			this->timer1->Enabled = false;
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) { return; }
			std::string filename = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
			if (filename == "") { return; }
			std::ofstream file;
			file.open(filename);

			file << x1 << std::endl << x2 << std::endl << y1 << std::endl << y2 << std::endl << startX << std::endl;

			cli::array <System::Drawing::PointF>^ array_points = Points->ToArray();

			for each (System::Drawing::PointF ^ t in array_points) {
				file << t->X << std::endl;
				file << t->Y << std::endl;
			}
			file.close();
		}

		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) { // Таймер сдвига графика
			x1 += xstep;
			x2 += xstep;
			drow_Graf();
		}

		System::Void pictureBox1_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) // Скролл
		{
			if (e->Delta > 0) {
				this->button5_Click(sender, e);
				this->button7_Click(sender, e);
			}
			else {
				this->button6_Click(sender, e);
				this->button8_Click(sender, e);
			}
		}

		System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) { // Масштабирование формы
			pw = pictureBox1->Width, ph = pictureBox1->Height;
			if (pw == 0 || ph == 0) {
				this->button1_Click(sender, e);
			}
			else {
				init_parametrsX();
				init_parametrsY();
				drow_Graf();
			}
		}
	};
}
